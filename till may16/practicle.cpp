/*#include<iostream>
#include<list>
#include<map>
using namespace std;
class graph{
    map<int,list<int> > adjlist;
public:
    void addElement(int u,int v,bool bidr=true){
        adjlist[u].push_back(v);
        if(bidr){
            adjlist[v].push_back(u);
        }
    }
    void print(){
        map<int,list<int> >::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            cout<<it->first<<" => ";
            int vertex=it->first;
            list<int>::iterator i;
            for(i=adjlist[vertex].begin();i!=adjlist[vertex].end();i++){
                cout<<*i<<",";
            }
            cout<<endl;
        }
    }


};
int main()
{
    graph g;
    g.addElement(0,1);
    g.addElement(0,2);
    g.addElement(2,3);
    g.addElement(3,4);
    g.addElement(2,4);
    g.addElement(4,5);
    g.addElement(3,1);
    g.print();

}
*/


#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<T,list<T> > adjlist;
public:
    void addElement(T u,T v,bool bidr=true){
        adjlist[u].push_back(v);
        if(bidr){
            adjlist[v].push_back(u);
        }
    }
    void print(){
        map<int,list<int> >:: iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            cout<<it->first<<"-> ";
            list<int>::iterator it2;
            for(it2=it->second.begin();it2!=it->second.end();it2++){
                cout<<*it2<<", " ;
            }
        cout<<endl;
        }
    }
    void bfs(int src){
        queue <int> q;
        map<int,bool> visited;
        map<int,bool>::iterator i;
        for(i=visited.begin();i!=visited.end();i++){
           i->second=false;
        }
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cout<<top<<", ";
            list<int>::iterator it;
            for(it=adjlist[top].begin();it!=adjlist[top].end();it++){
                if(!visited[*it]){
                    visited[*it]=true;
                    q.push(*it);
                }
            }
        }
    }
 void dfs_helper(int source,map<int,bool> &visited){
            if(visited[source]){
                return;
            }
            visited[source]=true;
            cout<<source<<" ";
            list<int>::iterator it;
            for(it=adjlist[source].begin();it!=adjlist[source].end();it++){
                dfs_helper(*it,visited);
            }
        }
        void dfs(int source){
            map<int,bool> visited;
            dfs_helper(source,visited);
        }
};
int main()
{
    graph<int>g;
    g.addElement(0,1);
    g.addElement(0,2);
    g.addElement(2,3);
    g.addElement(3,4);
    g.addElement(2,4);
    g.addElement(4,5);
    g.addElement(3,1);
    g.print();
    g.bfs(1);

    cout<<endl;
    g.dfs(1);

}
