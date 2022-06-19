#include<iostream>
using namespace std;
int counter=0;
void merge(int nums[], int front, int mid, int rear) {
    counter++;
    int newNums[100];
    int i=front, j= mid+1, k= front;
    while(i<=mid && j<= rear) {
        if(nums[i]<= nums[j]) {
            newNums[k]= nums[i];
            i++;
            k++;
        }
        else {
            newNums[k]= nums[j];
            j++;
            k++;
        }
    }
    while(i<=mid) {
        newNums[k]= nums[i];
        i++;
        k++;
    }
    while(j<=mid) {
        newNums[k]= nums[j];
        j++;
        k++;
    }
    for(int i=0;i<k;i++) {
        nums[i]=newNums[i];
    }
}
void mergeSort(int nums[], int front, int rear) {
    if(front<rear) {
        int mid= (front+rear)/2;
        mergeSort(nums, front, mid);
        mergeSort(nums, mid+1, rear);
        merge(nums, front, mid, rear);
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
    mergeSort(nums, 0, numsSize-1);
    cout<<"the sorted array output is as follows"<<endl;
    for(int i=0;i<numsSize;i++) {
        cout<<nums[i]<<" ";
    }
    cout<<"\nthe output goes as follows"<<counter<<endl;
}