#include<iostream>
using namespace std;
class BinarySearch {
    public:
        float counter,x;
        float binarySearch(int nums[], int size, int front, int mid, int rear, int num, float counter) {
            mid= (front+rear)/2;
            if(front<=rear)
            {
                counter++;
                if(nums[mid]==num) {
                    x=counter;
                }
                else if(nums[mid]>num)
                {
                    rear=mid-1;
                    binarySearch(nums, size, front, mid, rear, num,counter);
                }
                else
                {
                    front=mid+1;
                    binarySearch(nums, size, front, mid, rear, num,counter); 
                }
                return x;
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
    BinarySearch b1;
    int it;
    cin>>it;
    float sum=0, temp=0;
    for(int i=0;i<it;i++) {
        int num= rand()%10;
        temp= b1.binarySearch(nums, size, 0, 0, size-1, num,0);
        sum=sum+temp;
    }
    sum=sum/it;
    cout<<"the time complexity comes out to be:"<<sum<<endl;
    return 0;   
}
