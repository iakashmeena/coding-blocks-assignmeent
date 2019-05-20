/*
FIND MID OF STACK
Implement a stack such that the operation findMid() is performed in linear time complexity i.e. in O(1). findMid() is a function which returns the middle element of the stack.


Input Format:
First line contains the number of elements in stack,N. Next line contains N elements of stack.
*/

#include<bits/stdc++.h>
using namespace std;
int findMid(stack<int>&s,int n){
    int midElement;
    n=(n/2);
    while(n){
        s.pop();
        --n;
    }
    return s.top();
}
int main()
{
    stack<int>s;
    int n;
    int number;
    cin>>n;
    int it=n;
    while(it){
        cin>>number;
        s.push(number);
        it--;
    }
    cout<<findMid(s,n);
}
