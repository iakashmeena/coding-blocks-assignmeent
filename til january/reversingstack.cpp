#include<iostream>
using namespace std;
template<typename T>
struct node{
    node *next;
    T data;
   node(T data){
        this->data=data;
    }
};
template<typename T>
struct stack{
private:
    node<T>* head;
    int sizen;
public:
    stack(){
        head=NULL;
        sizen =0;
    }
    bool isempty(){
        if(sizen==0){
            head=NULL;
            return 1;
        }
        return 0;
    }
    int  size(){
        return sizen;
    }
    void push(T da){
        node<T>*temp=new node<T>(da);
        if(isempty()==1){
            temp->next = NULL;
            head=temp;
            sizen++;
            return;

        }
        temp->next=head;
        head=temp;
        sizen++;
        return;
    }
    void pop(){
        if(isempty()==1){
            return ;
        }
        node<T>*it =head;
        head=head->next;
        delete it;
        sizen--;
        return;
    }
     T top(){
         if(isempty()){
            return -1;
         }
        return head->data;
    }

};
template<typename T>
void reversestack(stack<T> &s){
    stack<T> s2;
    //int a;
    int i=s.size();
    while(i>1){
        T k=s.top();
        s.pop();
        for(int l=1;l<i;l++){
            T p=s.top();
             s.pop();
            s2.push(p);

        }
        s.push(k);
        for(int l=1;l<i;l++){
            T h=s2.top();
            s2.pop();
            s.push(h);

        }
        i--;
    }

}
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    reversestack(s);
     cout<<s.top()<<endl;
    s.pop();
      cout<<s.top()<<endl;
    s.pop();
      cout<<s.top()<<endl;

}
