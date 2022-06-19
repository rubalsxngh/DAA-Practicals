#include<iostream>
using namespace std;
void print(float x[], int size) {
    for(int i=0;i<size;i++) {
        cout<<x[i]<<" ";
    }
}
void FracKnapsack(float weight[], float profit[], int size, float sizeKnap) {
    float x[size];
    for(int i=0;i<size;i++) {
        x[i]=0;
    }
    float profits=0;
    while(sizeKnap>0) {
        int counter= distance(weight, min_element(weight, weight+size));
        if(weight[counter]<=sizeKnap) {
            x[counter]= 1;
            sizeKnap= sizeKnap- weight[counter];
            profits= profits+ profit[counter];
            weight[counter]= 9999;
        }
        else {
            x[counter]= sizeKnap/ weight[counter];
            sizeKnap= sizeKnap- weight[counter];
            profits= profits+ (x[counter]* profit[counter]);
            weight[counter]= 9999;
        }
    }
    cout<<"the total profit is"<< profits<<endl;
    print(x, size);
}
int main() {
    int size;
    float sizeKnap;
    cout<<"please enter the size of arrays and knapsack"<<endl;
    cin>>size>>sizeKnap;
    float weight[size], profit[size];
    cout<<"lets create the weight array"<<endl;
    for(int i=0;i<size;i++) {
        cin>>weight[i];
    }
    cout<<"lets create the profit array"<<endl;
    for(int i=0;i<size;i++) {
        cin>>profit[i];
    }
    cout<<endl;
    FracKnapsack(weight, profit, size, sizeKnap);
}