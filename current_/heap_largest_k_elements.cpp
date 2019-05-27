#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > min_heap;
    int data;
    cin>>data;
    while(data!=-1){
        if(min_heap.size()==3){
            if(min_heap.top()<data){
                min_heap.pop();
                min_heap.push(data);;
            }
        }
        else if(min_heap.size()<4){
            min_heap.push(data);
        }
        cin>>data;
    }
    cout<<endl;
    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
}
