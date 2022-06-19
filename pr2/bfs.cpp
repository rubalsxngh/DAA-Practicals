#include<iostream>
#include<list>
using namespace std;
class bsftrav
{
    public:
    int source;

    void getsource(int s)
    {
        source=s;
    }
    void bsf()
    {
        int size;
        cout<<"please enter the size of the cost matrix"<<endl;
        cin>>size;
        int cost[size][size];
        cout<<"lets craete the cost matrix"<<endl;
        
        int visited[size];
        for(int i=0;i<size;i++)
        {
            visited[i]=0;
        } //array to check the visited nodes
        int queue[size];
        int front=-1;
        int rear=-1;
        visited[0]=1;
        front=0;
        rear=0;
        queue[rear]=source;

        while(front<=rear)
        {
            int temp= queue[front];
            front++;
            cout<<temp<<endl;
            for(int i=0;i<size;i++)
            {
                if(visited[i]==0 && cost[temp][i]==1)
                {
                    rear++;
                    queue[rear]=i;
                    visited[i]=1;
                }
            }
        }
    }
};
int main()
{
    bsftrav d1;
    d1.getsource(0);
    d1.bsf();
    return 0;
}