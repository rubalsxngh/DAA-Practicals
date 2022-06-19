#include<iostream>
using namespace std;
class BinarySearch {
    public:
        int counter;
        BinarySearch(int counterT) {
            counter= counterT;
        }
        int binarySearch(int nums[], int size, int front, int mid, int rear, int num, int counter){
            counter++;
            mid= (front+rear)/2;
            if(front<=rear)
            {
                if(nums[mid]==num)
                {
                    return counter;
                }
                else if(nums[mid]>num)
                {
                    rear=mid-1;
                    binarys(nums, size, front, mid, rear, num,counter);
                }
                else
                {
                    front=mid+1;
                    binarys(nums, size, front, mid, rear, num,counter); 
                }
            }
        }
};
int main() {
    int size; 
    cout<<"please enter the size of the array"<<endl;
    cin>>size;
    int nums[size];
    cout<<"lets create the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>nums[i];
    } 
    BinarySearch b1(0);
    int it;
    cin>>it;
    int sum=0;
    for(int i=0;i<it;i++) {
        int num;
        cout<<"please enter the number to search"<<endl;
        cin>>num;
        int sumt=binarySearch(nums, size, 0, 0, size-1, num,0);
        sum=sum+sumt;
    }
    sum=sum/it;
    cout<<"the time complexity comes out to be:"<<sum<<endl;
    return 0;   
}
