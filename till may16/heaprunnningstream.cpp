#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    priority_queue<int,vector<int>/*,greater<int>*/ >pq;
    int cs=0;
    int k=3;
    int n;
    cin>>n;
    while(n!=-1){
        if(cs<k){
            pq.push(n);
            cs++;
        }
        else{
            if(pq.top()>n){
                pq.pop();
                pq.push(n);
            }
        }
        cin>>n;

    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

