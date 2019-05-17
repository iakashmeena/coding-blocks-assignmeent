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


    ///not working correctly
    void bfsLevelorder(int src){
        queue<int>q;
        int dis[100];
        for(int i=0;i<100;i++){
            dis[i]=INT_MAX;
        }
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            list<int> :: iterator i;
            for(i=adjlist[top].begin();i!=adjlist[top].end();i++){
                if(dis[*i]==INT_MAX){
                    q.push(*i);
                    dis[*i]=dis[top]+1;
                }
            }

        }

        map<int ,list<int> >::iterator i1;
        for(i1=adjlist.begin();i1!=adjlist.end();i1++){
            //list<int>::iterator i2;
            ///for(i2=i1->second.begin();i2!=i1->second.end();i2++){
                int node= i1->first;
                cout<<"dist of "<<src<<" and "<<node<<" "<<dis[node]<<endl;
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
    void topodriver(int v,stack<int> &s,bool arr[]){
        if(arr[v]==1){
            return;
        }
        arr[v]=1;

        list<int>::iterator it;
        for(it=adjlist[v].begin();it!=adjlist[v].end();it++){
            int vertex=*it;
            topodriver(vertex,s,arr);
        }
    }

    void topogical_sort(){
        stack<int>s;
        bool arr[]={0};
        map<int,list<int> >::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            topodriver(it->first,s,arr);
        }
        while(!s.empty()){
            cout<<s.top();
            cout<<endl;
        }
    }
    bool cycledriver(int vertex,bool visited[],bool instack[]){
        visited[vertex]=true;
        instack[vertex]=true;
        list<int>::iterator it;
        for(it=adjlist[vertex].begin();it!=adjlist[vertex].end();it++){
            if((!visited[vertex] && cycledriver(*it,visited,instack)) || instack[vertex]){
                return true;
            }
        }
        return false;

    }
    bool is_cycle(){
        bool visited[]={0};
        bool instack[]={0};
        map<int ,list<int> >::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            bool cycle=cycledriver(it->first,visited,instack);
            if(cycle==1){
                return true;
            }
        }
        return false;
    }

};
int main()
{
    graph<int> g;
    g.addElement(0,2,0);
    g.addElement(0,1,0);
    g.addElement(2,3,0);
    g.addElement(2,4,0);
    //g.addElement(3,0,0);
    g.addElement(1,5,0);
    g.addElement(4,5,0);

    g.bfs(1);
    cout<<endl;
    //g.bfsLevelorder(1);
    //g.topogical_sort();
    cout<<g.is_cycle();

}
