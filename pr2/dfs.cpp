#include<iostream>
using namespace std;
class DsfTraversel {
    public:
    int source;

    void getsource(int s) {
        source=s;
    }
    void dsf() {
        int size;
        cout<<"please enter the size of the cost matrix"<<endl;
        cin>>size;
        int cost[size][size];
        cout<<"lets craete the cost matrix"<<endl;
        for(int i=0;i<size;i++)
        {
        for(int j=0;j<size;j++)
            {
                cin>>cost[i][j];
            }
        } //adjancency matrix created
        int visited[size];
        for(int i=0;i<size;i++) {
            visited[i]=0;
        } //array to check the visited nodes
        int stack[size];
        int top=-1;
        visited[0]=1;
        top++;
        stack[top]=source;

        while(top!=-1) {
            int temp= stack[top];
            top--;
            cout<<temp<<endl;
            for(int i=0;i<size;i++)
            {
                if(visited[i]==0 && cost[temp][i]==1)
                {
                    top++;
                    stack[top]=i;
                    visited[i]=1;
                }
            }
        }
    }
};
int main() {
    DsfTraversel d1;
    d1.getsource(0);
    d1.dsf();
    return 0;
}