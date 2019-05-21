/*
SORT A STACK (RECURSION)
Sort a given stack using recursion. In the recursive function use only basic functions of stack like push, pop etc.


Input Format:
First line contains the number of elements in stack , N. Next line contains N elements in stack from bottom to top.
*/

#include<bits/stdc++.h>
using namespace std;
///TO ARRANGE THE STACK IN THE WANTED FORMAT
void arrange_stack(stack<int>&s,int &top){
    if(s.empty()){
        s.push(top);
        return;
    }
    if(s.top()>top){
        int temp=s.top();
        s.pop();
        arrange_stack(s,top);
        s.push(temp);
        return;
    }
    s.push(top);
    return;

}
///DEVIDE AND CCONQUER
void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    sortStack(s);
    arrange_stack(s,top);
    return;
}

int main()
{
    stack<int>s;
    int n;
    cin>>n;
    int it=n;
    while(it--){
        int number;
        cin>>number;
        s.push(number);
    }
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
