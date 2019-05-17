#include<iostream>
#include<list>
#include<queue>
#include<stack>
using namespace std;
class graph{
    int V;  // count of vertex
    list<int>* l;
public:
    graph(int v){
        V = v;
        l = new list<int> [v];
    }
    void addEdge(int u,int v, bool bidir = true){
        l[u].push_back(v);
        if(bidir){
           l[v].push_back(u);
        }
    }
    void  bfs(int vertex){
        //bool * visited = new bool[100];
        bool visited[100] = {0};
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            cout<<top<<" ";
            list<int>:: iterator it;
            for(it=l[top].begin();it!=l[top].end();it++){
                if(visited[*it]==false){
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }

};
int main(){
graph g(7);
g.addEdge(0,1,0);
g.addEdge(0,2,0);
g.addEdge(0,3,0);
g.addEdge(1,4,0);
g.addEdge(2,3,0);
g.addEdge(2,4,0);
g.addEdge(3,4,0);
g.addEdge(5,6,0);

}
