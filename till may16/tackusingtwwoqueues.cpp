#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int>q1;
    queue<int>q2;
public:
    bool isempty(){
        if(q1.empty()==1){
            return 1;
        }
        return 0;
    }
    void push(int data){
        q1.push(data);
    }
    void pop(){
        if(isempty()==1){
            return ;
        }
        while(q1.empty()==0){
           int x=q1.front();
           q1.pop();
            if(q1.empty()){
                break;
            }
            else{
                q2.push(x);
            }
        }
        while(q2.empty()==0){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top(){
        if(isempty()==1){
            return 0;
        }
        int x;
        int y;
        while(!q1.empty()){
           x=q1.front();
           q1.pop();
           q2.push(x);
           if(q1.empty()){
            y=x;
           }
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return y;
    }


};
int main()
{
    stack s;
    for(int i=1;i<6;i++){
        s.push(i);
    }
   while(!s.isempty()){
        cout<<s.top()<<"  ";
        s.pop();
    }

}
