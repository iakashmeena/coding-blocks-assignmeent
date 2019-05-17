#include<bits/stdc++.h>
#include<set>
using namespace std;

template<typename T>
class graph{
    map<T,list < pair<T,int> > > adjlist;
public:
    void insert(T u,T vertex,int weight=0,bool bidr=true){
        adjlist[u].push_back(make_pair(vertex,weight));
        if(bidr==true){
            adjlist[vertex].push_back(make_pair(u,weight));
        }
    }
    void print(){
        //auto::iterator it:
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            cout<<it->first<<"==>";

            for(auto it2=it->second.begin();it2!=it->second.end();it2++){
                cout<<it2->first<<"<"<<it2->second<<">"<<"->";

            }
            cout<<endl;
        }
    }
    void bfs(T vertex){
        queue<T> q;
        map<T,bool> visited;
        for(auto it=visited.begin();it!=visited.end();it++){
            it->second=false;
        }
        q.push(vertex);
        visited[vertex]=true;
        while(!q.empty()){
            T top=q.front();
            cout<<top;
            q.pop();
            for(auto it=adjlist[top].begin();it!=adjlist[top].end();it++){
                if(!visited[it->first]){
                    q.push(it->first);
                    visited[it->first]=true;
                }
            }
        }
    }
    void dfshelper(T source,map<T,bool> &visited){
        if(visited[source]==true){
            return;
        }
        visited[source]=true;
        cout<<source;
        for(auto it=adjlist[source].begin();it!=adjlist[source].end();it++){
            dfshelper(it->first,visited);
        }
    }
    void  dfs(T vertex){
        map<T,bool> visited;
        for(auto it=visited.begin();it!=visited.end();it++){
            it->second=false;
        }
        dfshelper(vertex,visited);
    }
    void topodriver(T source,stack<T>&s,map<T,bool> &visited){
       if(visited[source]==true){
            return;
       }
       if(adjlist[source].empty()){
            s.push(source);
            visited[source]=true;
            return;
       }

       visited[source]=true;
       for(auto it=adjlist[source].begin();it!=adjlist[source].end();it++){
            topodriver(it->first,s,visited);
       }
       s.push(source);
    }
    void toposort(){
        map<T,bool>visited;
        for(auto it=visited.begin();it!=visited.end();it++){
            it->second=false;
        }
        stack<T>s;
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            topodriver(it->first,s,visited);
        }

        while(!s.empty()){
            cout<<s.top()<<"==>";
            s.pop();
        }
    }
    ///topological sort by bfs
    void topo2(){
        map<T,bool>visited ;
        queue<T>q;
        map<T,int>indegree;

        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            //it->second=false;
            indegree[it->first]=0;
        }
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            for(auto it2=it->second.begin();it2!=it->second.end();it2++){
                indegree[it2->first]++;
            }
        }
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            if(indegree[it->first]==0){
                q.push(it->first);
            }
        }
        while(!q.empty()){
            T top=q.front();
            q.pop();
            cout<<top<<"=>";
            for(auto it=adjlist[top].begin();it!=adjlist[top].end();it++){
                indegree[it->first]--;
                if(indegree[it->first]==0){
                    q.push(it->first);
                }
            }
        }
    }
    ///iscycle for undirected
    bool cycle_driver(T src,map<T,bool>&visited,T parent){
        if(visited[src]==true){
            return true;
        }
        visited[src]=true;
        for(auto it:adjlist[src]){
            if(it.first!=parent){
                bool cycle=cycle_driver(it.first,visited,src);
                if(cycle==true){
                    return true;
                }
            }


        }
        return false;
    }

    bool iscycle(){
        map<T,bool>visited;
        for(auto it:adjlist){
            visited[it.first]=false;
        }

        for(auto it:adjlist){
            if(!visited[it.first]){
                bool cycle=cycle_driver(it.first,visited,it.first);
                if(cycle==true){
                return true;
                }
            }
        }
        return false;
    }
    ///is cycle directional
    bool iscycledriver(T src,map<T,bool>&visited,map<T,bool>&checkInstack){
        if(visited[src]==true && checkInstack[src]==true){
            return true;
        }
        if(visited[src]==false){
            visited[src]=true;
            checkInstack[src]=true;
            for(auto it:adjlist[src]){
                bool cycle=iscycledriver(it.first,visited,checkInstack);
                if(cycle==true){
                    return true;
                }
            }
        checkInstack[src]=false;
        }

        return false;
    }
    bool iscycledir(){
        map<T,bool>visited;
        map<T,bool>checkInstack;
        for(auto it:adjlist){
            visited[it.first]=false;
            checkInstack[it.first]=false;
        }
        for(auto it:adjlist){
            bool cycle=iscycledriver(it.first,visited,checkInstack);
            if(cycle==true){
                return true;
            }
        }
    return false;
    }
    void dijkstras(T src){
        map<T,int>dist;
        set<pair<int,T> >que;
        for(auto it:adjlist){
            dist[it.first]=INT_MAX;
        }
        dist[src]=0;
        que.insert(make_pair (0,src));
        while(!que.empty()){
            auto node=*(que.begin());
            T nodename=node.second;
            int nodedist=node.first;
            que.erase(node);
            for(auto it:adjlist[nodename]){
                if(nodedist+it.second<dist[it.first]){
                    auto p=que.find(make_pair( dist[it.first],it.first ) );
                    if(p!=que.end()){
                       que.erase(p);
                    }
                    que.insert(make_pair(nodedist+it.second,it.first));
                    dist[it.first]=nodedist+it.second;
                }
            }
        }
        for(auto it:dist){
            cout<<it.first<<"==>("<<it.second<<")"<<endl;
        }

    }


};

int main()
{
    graph <int> g;


    /*g.insert(1,5);
    g.insert(1,2);
    g.insert(2,3);
    g.insert(2,4);
    ///g.insert(3,1);
    g.insert(4,6);
    g.insert(5,6);
    /*
    g.insert(7,8);
    g.insert(4,8);
    g.insert(5,9);
    g.insert(8,9);
    g.insert(6,9);*/

   /* g.insert("english","programing language");
    g.insert("english","html");
    g.insert("maths","programing language");
    g.insert("programing language","html");
    g.insert("programing language","js");
    g.insert("programing language","python");
    g.insert("programing language","java");
    g.insert("html","css");
    g.insert("css","js");
    g.insert("js","webd");
    g.insert("python","webd");
    g.insert("java","webd");
    g.print();
    cout<<endl;
    g.bfs(1);
    cout<<endl;
    g.dfs(1);
    cout<<endl;
   /// g.toposort();
    cout<<endl<<endl;
    g.topo2();
    cout<<g.iscycledir();*/
    ///dijksras
    g.insert(1,2,1);
    g.insert(1,3,4);
    g.insert(1,4,7);
    g.insert(3,2,1,false);
    g.insert(3,4,2);
    g.dijkstras(1);
}
