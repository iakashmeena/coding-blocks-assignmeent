#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > p;
    int k;
    cin>>k;
    int n;
    cin>>n;

    while(n!=-1){
        if(n>p.top()){
            p.push(n);
        }
    }
    while(p!=NULL){
    cout<<p.front()<<endl;
    p.pop();
    }


}
