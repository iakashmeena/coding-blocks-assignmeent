/*
DEQUEUE EFFICIENT QUEUE USING STACK
Implement a Queue using two stacks Make it Dequeue efficient.


Input Format:
Enter the size of the queue N add 0 - N-1 numbers in the queue

Output Format:
Display the numbers in the order they are dequeued and in a space separated manner
*/
#include<bits/stdc++.h>
using namespace  std;
class queue_{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int data){
        s1.push(data);
    }
    void pop(){
        while(!s1.empty()){
            int top=s1.top();
            s1.pop();
            if(s1.empty()){
                break;
            }
            s2.push(top);
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int top(){
        int number;
        while(!s1.empty()){
            int top=s1.top();
            s1.pop();
            if(s1.empty()){
                number=top;
            }
            s2.push(top);
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return number;
    }
    bool isEmpty(){
        if(s1.empty()){
            return 1;
        }
        return 0;
    }
};
int main()
{
    queue_ q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    while(!q.isEmpty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}
