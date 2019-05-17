//heap basic
/*

#include<iostream>
#include<vector>
using namespace std;
//min heap example
class heap{
    vector<int>v;
    void heapify(int i){
        int minindex=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size()&&v[left]<v[i]){
            minindex=left;
        }
        if(right<v.size()&&v[right]<v[i]){
            minindex=right;
        }
        if(minindex!=i){
            swap(v[i],v[minindex]);
            heapify(minindex);
        }
    }
public:
    heap(){
        v.push_back(-1);
    }
    void addelement(int data){
        v.push_back(data);
        int index=v.size()-1;
        while(index>1&&v[index/2]>v[index]){
            swap( v[index],v[index/2] );
            index=index/2;
        }
    }
    int removetop(){
        int top=v[1];
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
        return top;
    }
    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    bool isempty(){
        if(v.size()==1){
            return true;
        }
        return false;
    }
};
int main()
{
    heap h;
    h.addelement(1);
    h.addelement(2);
    h.addelement(3);
    h.addelement(4);
    h.addelement(0);
    h.print();
    cout<<endl;
    cout<<h.removetop();
    cout<<endl;
    h.print();
    cout<<endl;

}
        */


//use of inbuilt library
/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int> >pq;   // by default greater
    pq.push(5);
    pq.push(2);
    pq.push(9);
    pq.push(4);
    pq.push(10);
    pq.push(1);
    pq.push(2);
    pq.push(4);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();

    }
}
            */
//using custom comperator
#include<iostream>
#include<queue>
#include<functional>
#include<bits/stdc++.h>
using namespace std;
class car {
public:
    int x;
    int y;
    int id;
    car(int id,int a,int b){
        this->id=id;
        x=a;
        y=b;
    }
    int dis(){
        return x*x+y*y;
    }
    void print(){
        cout<<"id "<<id<<" x "<<x<<" y "<<y<<endl;

    }
};
//founter
class carcompare{
public:
    bool operator()(car a,car b){
        return a.dis() > b.dis();
    }
};
int main()
{
    priority_queue<car,vector<car>,carcompare >c;
    int x[]={1,2,3,4,5,6,7};
    int y[]={7,7,7,7,7,7,7};
    for(int i=0;i<7;i++){
        car p(i,x[i],y[i]);
        c.push(p);
    }
    while(!c.empty()){
        car p=c.top();
        p.print();
        cout<<endl;
        c.pop();
    }
}
