/*
REVERSE A STACK USING RECURSION
Reverse a Stack using Recursion.


Input Format:
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack
where the last integer is at the top of the stack.
*/
#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&s,int top){
    if(s.empty()){
        s.push(top);
        return;
    }
    int temp;
    temp=s.top();
    s.pop();
    insert_at_bottom(s,top);
    s.push(temp);
}

void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    reverseStack(s);
    insert_at_bottom(s,top);
}
int main()
{
    stack<int>s;
    int n;
    cin>>n;
    while(n--){
        int number;
        cin>>number;
        s.push(number);
    }
    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}
