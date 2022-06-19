#include<stdio.h>

int main()
{
    int temp, temp1;
    int nums[6]={-4,-2,1,2,4,8};
    int closest=nums[0];
    for(int i=0;i<5;i++)
    {
        int temp=nums[i];
        int temp1=nums[i+1];

        if(temp<0)
        {
            temp= temp-temp-temp;
        }
        if(temp1<0)
        {
            temp1=temp1-temp1-temp1;
        }

        if(temp>=temp1)
        {
            closest=nums[i+1];
        }
    }
    printf("%d",closest);
}