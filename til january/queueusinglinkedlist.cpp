#include<iostream>
using namespace std;
template<typename T>
struct node{
    node* next;
    T data;
};
template<typename T>
class queue{
    node <T>*head;
    node <T>*tail;
    int size ;
public:
    queue(){
        head=NULL;
        size=0;
    }

   bool isempty(){
    if(head==NULL){
        return 1;
    }
    return 0;
   }
    int sizeofque(){
        return size;
    }
    void enqueue(T da){
        //node<T>*it=head;
        node<T>*temp=new node<T>;
        size++;
        if(isempty()){
            head =temp;
            tail=temp;
            head->data=da;
            size ++;
            return;
        }
        temp->data=da;
        tail->next =temp;
        tail=temp;

        return;
        }

    void dequeue(){
        node<T>*it=head;
        head=head->next;
        delete it;
        size--;
        return;
    }
    T top(){
        return head->data;
    }
};
int main()
{
    queue <int>s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    cout<<s.top()<<endl;
    s.dequeue();
    cout<<s.top()<<endl;
    s.dequeue();
    cout<<s.top()<<endl;
    //dequeue();


}
