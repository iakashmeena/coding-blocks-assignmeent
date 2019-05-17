#include<iostream>
#include<vector>
using namespace std;
//stack using vector
template<typename T>
class stack{
    vector<T>v;
public:
    bool isempty(){
        if(v.size()==0){
            return 1;
        }
        return 0;
    }
    void push(T data){
        v.push_back(data);
    }
    void pop(){
        if(isempty()==1){
            return;
        }
        v.pop_back();
    }
    int size(){
        return v.size();
    }
    T top(){
        if(isempty()){
            return NULL;
        }
        return v[v.size()-1];
    }

};
//stack using linked list
template<typename T>
struct node{
    T data;
    node*next;
    node(T data){
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class stack2{
    node<T>*head;
    int n;
public:
    stack2(){
        head=NULL;
        n=0;
    }
    bool isempty(){
        if(n==0){
            return 1;
        }
        return 0;
    }
    int size(){
        return n;
    }
    void push(T data){
        node<T>*temp=new node<T>(data);
        if(isempty()==1){
            head=temp;
            n++;
            return;
        }
        temp->next=head;
        head=temp;
        n++;
    }
    void pop(){
        node<T>*it=head;
        head=head->next;
        delete it;
        --n;
    }
    T top(){
        if(isempty()==1){
            return 0;
        }
        return head->data;
    }

};


int main()
{
    stack2<char>s;
    char a;
    cin>>a;
    s.push(a);
    while(a!='$'){
        cin>>a;
        if(s.top()=='{'&& a=='}'){
            s.pop();
        }
        else if(s.top()=='}'&&a=='{'){
        s.pop();
        }
        else if(s.top()=='}'&&a=='{'){
        s.pop();
        }
        else if(s.top()=='('&&a==')'){
        s.pop();
        }
        else if(s.top()==')'&&a=='('){
        s.pop();
        }
        else if(s.top()=='['&&a==']'){
        s.pop();
        }
        else if(s.top()==']'&&a=='['){
        s.pop();
        }
        else{
            s.push(a);
        }
        if(s.top()=='$'){
            s.pop();
        }
    }
    if(s.isempty()){
        cout<<"done"<<endl<<s.size();
    }
    else{
        cout<<"not done"<<endl<<s.size();
    }



}
