#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph {
    int v;
    list<int> *l;

public:
    Graph(int v) {
        this->v= v;
        l= new list<int>[v];
    }
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int source) {
    int visited[100] = {true};
    queue<int> q;
    q.push(source);
    visited[source]= true;
    while(!q.empty()) {
        int node= q.front();
        q.pop();
        cout<<node<<endl;
        for(int nbr: l[node]) {
            if(!visited[nbr]) {
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }
}
};
int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.bfs(0);
}