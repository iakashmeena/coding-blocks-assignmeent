#include<iostream>
using namespace std;
struct node{
     int data;
     node * next;
     node(){

     }
     node(int data){
     this->data = data;
     this->next = NULL;
     }
 };
 node * createlinklist(){
     node * head = 0;
     int data;
     cout<<"Enter data and -1 to exit"<<endl;
     cin>>data;
     if(data!=-1){
         head =  new node();
         head->data = data;
         head->next = NULL;
     }
     node * it = head;
     cin>>data;
     while(data!=-1){
         node * temp = new node();
         temp->data = data;
         temp->next = NULL;
         it->next = temp;
         it = it->next;
         cin>>data;
     }
     return head;
 }
  void print(node * head){
     while(head!=NULL){
         cout<<head->data<<" ";
         head = head->next;
     }
 }
 int countnodes(node *head){
    int k=0;
    while(head->next!=NULL){
        head=head->next;
        k++;
    }
    return k;
 }
 void rearrange(node*head){
    int k=countnodes(head);
    node *it=head;
    node *even=it->next;
    node *eve=it->next;
    node *odd=head;
    if(it->next==NULL||it->next->next==NULL){
        return;
    }
    while(it->next!=NULL||it!=NULL){
            even->next=even->next->next->next;
            it=it->next->next;

    }
 }
int main()
{
    node *head;
    head=createlinklist();
    print(head);
    cout<<endl;
    rearrange(head);
    print(head);


}

