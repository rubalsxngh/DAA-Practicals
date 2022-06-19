#include<iostream>
using namespace std;

int main()
{
    int average=0;
    int size;
    cout<<"please enter the size"<<endl;
    cin>>size;
    int arr[size];

    int counter=0;

    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%10;
    }// random array created
    int iter;
    cout<<"plesae enter number of iterations"<<endl;
    cin>>iter;
    for(int i=0;i<iter;i++)
    {
        int nums;
        cout<<"plesae enter the number to be searched"<<endl;
        cin>>nums;

        //to search
        for(int i=0;i<size;i++)
        {
            if(arr[i]==nums)
            {
                break;
            }
            counter++;
        }
        average=(average+counter)/size;
    }

    cout<<average;
}
