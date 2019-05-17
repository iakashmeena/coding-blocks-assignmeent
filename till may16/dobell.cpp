#include<iostream>
using namespace std;
//template<typename T>
struct node{
    node*prev;
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
//template<typename T>
void createll(node *& head,int data){
    node* temp=new node(data);
    if(head==NULL){
        temp->prev=head;
        head=temp;
        return;
    }
    node*it=head;
    while(it->next!=NULL){
        it=it->next;
    }
    temp->prev=it;
    it->next=temp;
    return;
}
void insertatk(node*&head,int data,int k){
    node*temp=new node(data);
    if(k==0){
       // node*it=head->prev;
        head->prev=temp;
        temp->next=head;
        head=temp;
        return;
    }
    node*it=head;
   // node*it;
    while(--k){
        it=it->next;
       // it1=it1->next;

    }
    temp->prev=it;
    temp->next=it->next;
    it->next=temp;
    return;
}
void deleteatk(node*&head,int k){
    if(k==0){
        node*temp=head;
        node*it=head->prev;
        head=head->next;
        head->prev=it;
        delete(temp);
        return;
    }
    if(0<k){
        node*head2=head;
        while(--k){
            head2=head2->next;
            if(head2->next->next==NULL){
                node*temp=head2->next;
                head2->next=NULL;
                delete(temp);
                return;
            }
        }
    node*temp=head2->next;
    node*itprev=head2->next->prev;
    node*itnext=head2->next->next;
    head2->next=itnext;
    head2->next->prev=itprev;
    delete(temp);
    }
    return;

}
void printll(node*head){
    cout<<head<<endl;
    while(head){

        cout<<head->prev<<"->"<<head->data<<"->"<<head->next;
        cout<<endl;

        head=head->next;
    }
}
int main()
{
  // node<int> s;
    node*head=NULL;
    for(int i=0;i<6;i++){
        createll(head,i);
        //cout<<i;
    }
    printll(head);
    deleteatk(head,4);
    cout<<"***********************************"<<endl;
    printll(head);
    /*insertatk(head,-1,0);
    cout<<"**********************"<<endl;
    printll(head);*/
}
