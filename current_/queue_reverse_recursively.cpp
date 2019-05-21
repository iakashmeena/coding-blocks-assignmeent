/*
REVERSE A QUEUE(RECURSIVE)
Reverse a Queue using recursion.


Input Format:
Enter the size of the queue N and N more number and store in the queue.
*/

#include<bits/stdc++.h>
using namespace std;


void reverseQueue(queue<int>&q){
    if(q.empty()){
        return;
    }
    int top=q.front();
    q.pop();
    reverseQueue(q);
    q.push(top);
}
int main()
{
    queue<int>q;
    int n;
    cin>>n;
    while(n--){
        int number;
        cin>>number;
        q.push(number);
    }
    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"END";
}
