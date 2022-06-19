#include<iostream>
using namespace std;
int counter=0;
int partition(int nums[], int front, int rear) {
    int x=nums[rear];
    int i= front-1, j= front;
    for(int j=front;j<=rear-1;j++) {
        if(nums[j]<=x) {
            counter++;
            i++;
            int temp;
            temp= nums[i];
            nums[i]= nums[j];
            nums[j]=temp;
        }
    }
    int temp;
    temp= nums[i+1];
    nums[i+1]=nums[rear];
    nums[rear]=temp;
    return i+1;

}
void quickSort(int nums[], int front, int rear) {
    if(front<rear) {
        int part= partition(nums, front, rear);
        quickSort(nums, part+1, rear);
        quickSort(nums, front, part-1);
    }
}
int main() {
    int numsSize;
    cout<<"enter the size of the array"<<endl;
    cin>>numsSize;
    int nums[numsSize];
    cout<<"lets craete the array"<<endl;
    for(int i=0;i<numsSize;i++) {
        cin>>nums[i];
    }
    quickSort(nums, 0, numsSize-1);
    cout<<"the sorted array output is as follows"<<endl;
    for(int i=0;i<numsSize;i++) {
        cout<<nums[i]<<endl;
    }
    cout<<"the time complexity goes as follows"<<counter<<endl;
}