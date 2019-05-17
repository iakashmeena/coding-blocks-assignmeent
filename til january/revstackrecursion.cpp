#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>&q,int top){
    if(q.empty()==1){
        q.push(top);
        return;
    }
    int x=q.top();
    q.pop();
    insertatbottom(q,top);
    q.push(x);
}
void revesestack(stack<int>&q){
    if(q.empty()){
        return;
    }
    int top=q.top();
    q.pop();
    revesestack(q);
    insertatbottom(q,top);
}
using namespace std;
int main()
{
    stack<int>q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    revesestack(q);
    while(q.empty()==0){
        cout<<q.top()<<endl;
        q.pop();
    }
}
