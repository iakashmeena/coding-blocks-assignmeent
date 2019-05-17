#include<iostream>
using namespace std;
template<typename T>
class queue{
    T arr[100];
    int maxsize;
    int currsize;
    int front;
    int rear;
public:
    queue(int n){
        maxsize=n;
        currsize=0;
        front=0;
        rear=n-1;
    }
    bool isempty(){
        if(currsize==0){
            return 1;
        }
        return 0;
    }
    bool isfull(){
        if(currsize==maxsize){
            return 1;
        }
        return 0;
    }
    int size(){
        return currsize;
    }
    void  enqueue(T data){
        if(isfull()==1){
            return ;
        }
        rear=(rear+1)%maxsize;
        arr[rear]=data;
        currsize++;
        return;
    }
    void dequeue(){
        if(isempty()==1){
            return;
        }
        front=(front+1)%maxsize;
        currsize--;
    }
    T top(){
        if(isempty()==1){
            return 0;
        }
        return arr[front];
    }
};
int main()
{
    queue<int>q(5);
    for(int i=0;i<5;i++){
        q.enqueue(i);
    }
    for(int i=0;i<5;i++){
        cout<<q.top();
        q.dequeue();
    }
    cout<<q.top();
}
