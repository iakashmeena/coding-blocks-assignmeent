#include <iostream>
#include <set>
#include <unordered_map>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
    
    // No. of vertices
    int V;

    // Node: List of adjacent nodes with weight
    unordered_map<T, list<pair<T, int> > > adjList;
public:
    
    // MARK: Constructor
    Graph(int v) {
        V = v;
    }
    
    // Add edge function
    void addEdge(T u, T v, bool bidir = true, int weight = 0) {
        adjList[u].push_back(make_pair(v, weight));
        if(bidir)
            adjList[v].push_back(make_pair(u, weight));
    }
    
    // Print graph
    void print() {
        for(auto node: adjList) {
            T key = node.first;
            cout<<key<<" : ";
            for(pair<T,int> element: node.second) {
                cout<<element.first<<", ";
            }
            cout<<endl;
        }
    }
    
    // MARK: Dijkstra Single Source Shortest Path
    void dijkstra(T src) {
        set<pair<int, T> > pool;
        unordered_map<T, int> distance;
        
        
        for(auto node: adjList) {
            distance.insert(make_pair(node.first, INT_MAX));
            pool.insert(make_pair(INT_MAX, node.first));
        }
        
        distance[src] = 0;
        pool.insert(make_pair(0,src));
        while(!pool.empty()) {
            auto p = *(pool.begin());
            T node = p.second;
            int d = p.first;
            
            pool.erase(pool.begin());
            for(auto child: adjList[node]) {
                if(d + child.second < distance[child.first]) {
                    T dest = child.first;
                    auto it = pool.find(make_pair(distance[dest], dest));
                    if(it != pool.end) {
                        s.erase(it);
                    }
                    distance[child.first] = d + child.second;
                    s.insert(make_pair(distance[dest], dest));
                }
            }
        }
    }
};

int main() {
    Graph<string> g(6);
    g.addEdge("India", "USA", 500);
    g.addEdge("India", "Russia", 233);
    g.addEdge("China", "Russia", 170);
    g.addEdge("China","Pakistan", 50);
    g.addEdge("Russia", "Pakistan", 192);
    g.addEdge("Pakistan", "USA", 487);
    g.addEdge("Russia", "Brazil", 670);

    g.bfs("India", "Brazil");
    //g.print();
}
