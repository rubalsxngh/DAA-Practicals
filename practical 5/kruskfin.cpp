#include<iostream>
using namespace std;
const int v=4;
int parent[4];
int find(int x) {
    if(parent[x]!=x) {
        return find(parent[x]);
    }
    else {
        return x;
    }
}
void unio(int x, int y) {
    int fx= find(x);
    int fy= find(y);
    parent[fx]= fy;
}
void kruskals(int edge[][3], int v, int r) {
    int mst_cost=0, mst_edges=0, mst_ni=0,a ,b, w;
    for(int i=0;i<100;i++) {
        parent[i]=i;
    }
    //this while loop will work until vertex and edges are finished
    cout<<"the output is as follows"<<endl;
    while(mst_edges<v-1 || mst_ni<r) {
        a= edge[mst_ni][1];
        b= edge[mst_ni][2];
        w= edge[mst_ni][0];
        if(find(a)!= find(b)) {
            unio(a,b);
            mst_cost= mst_cost+w;
            cout<<w<<" "<<a<<"->"<<b;
            cout<<endl;
            mst_edges++;
        }
        mst_ni++;
    }
    cout<<"\n weight of mst is "<<mst_cost<<endl;
}
void minEdge(int cost[][v], int v) {
    bool visited[100]={false};
    int edge[100][3], r=0;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(cost[i][j]!=0 && visited[j]!=true && cost[i][j]!=999) {
                edge[r][0]= cost[i][j];
                edge[r][1]= i;
                edge[r][2]= j;
                visited[i]=true;
                r++;
            }
        }
    }
    //bubble sort for loop
    for(int i=0;i<r;i++) {
        for(int j=i+1;j<r;j++) {
            if(edge[i][0]>=edge[j][0]) {
                int temp[1][3];
                temp[0][0]= edge[i][0];
                temp[0][1]= edge[i][1];
                temp[0][2]= edge[i][2];

                edge[i][0]= edge[j][0];
                edge[i][1]= edge[j][1];
                edge[i][2]= edge[j][2];

                edge[j][0]= temp[0][0];
                edge[j][1]= temp[0][1];
                edge[j][2]= temp[0][2];

            }
        }
    } 
    kruskals(edge, v, r);
}
int main() {

    int cost[v][v];
    cout<<"lets create the cost matrix"<<endl;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            cin>>cost[i][j];
        }
    }
    minEdge(cost, v);
}