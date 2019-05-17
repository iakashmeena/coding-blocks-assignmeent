#include<iostream>
#include<queue>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //int count=0;
    int median;
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int> > min;
    cin>>n;
    while(n!=-1){
        if(max.empty()==1){
            max.push(n);
           // median=n;
        }
        else if(n<median){
            if(max.size()>min.size()){
                min.push(max.top());
                max.pop();
                max.push(n);
                //median=max.top();
            }
            else{
                max.push(n);
                //median=(max.top()+min.top())/2;
            }
        }
        else if(n>=median){
            if(min.size()>max.size()){
                max.push(min.top());
                max.pop();
                min.push(n);
                //median=max.top();
            }
            else{
                min.push(n);
               // median=(max.top()+min.top())/2;

            }
        }

        if(max.size()>min.size()){
            median=max.top();
        }
        else if(min.size()>max.size()){
            median=min.top();
        }
        else if(max.size()==min.size()){
            median=(max.top()+min.top())/2;
        }
        cout<<median<<" ";
        cout<<endl;
        cin>>n;
    }
}
