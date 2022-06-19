#include<iostream>
using namespace std;

class LinearSearch {
    private:
        int requiredNum, numsSize, nums[100],counter;
    
    public:
        LinearSearch(int numsSizeT) {
            numsSize= numsSizeT;
        }
        
        void createArray()
        {
            for(int i=0;i<numsSize;i++) {
                nums[i]=rand()%10;
            }
        }

        int search(int requiredNumT, int counter)
        {
            requiredNum= requiredNumT;
            for(int i=0;i<numsSize;i++) {
                counter++;
                if(nums[i]==requiredNum)
                {
                    break;
                }
            }
            return counter;
        }
    
};
int main()
{
    LinearSearch obj1(10);
    obj1.createArray();
    int sum=0, it=0;
    cout<<"please enter the number of test cases"<<endl;
    cin>>it;
    for(int i=0;i<it;i++) {
        int temp= rand()%10;
        int sum1=obj1.search(temp,0);
        sum= sum+sum1;
    }
    sum= sum/it;

    cout<<"the average runtime of code is:"<<sum<<endl;
    return 0;
}