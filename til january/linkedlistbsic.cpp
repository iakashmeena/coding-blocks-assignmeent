#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
void pushinlist(int data,node *& head){
    node*temp=new node(data);
    if(head==NULL){
        head=temp;
        return;
    }
    node*it=head;
    while(it->next!=NULL){
        it=it->next;
    }
    it->next=temp;
    return;
}
void deletekfromlast(int k,node*&head){
    static int i=k;
    if(head==NULL){
        return;
    }
    deletekfromlast(k,head->next);
    if(i--==1){
        node*temp=head;
        head=head->next;
        delete temp;
        return;
    }
}
void inserttkposition(node *&head ,int data,int k){
    node*temp=new node(data);
    if(k==0){
        temp->next=head;
        head=temp;
        return;
    }
    node*it =head;
    while(--k){
        it=it->next;
    }
    temp->next=it->next;
    it->next=temp;

}
node*findatpositionk(node*head,int k){
    if(k==0){
        return head;
    }
    while(k--){
        head=head->next;
    }
    return head;
}
void swapnode(node*&head,int i,int j){
    if(i==0&&j==1){
        node*temp=head;
        head=head->next;
        temp->next=head->next;
        head->next=temp;
        return;
    }
    if(j-i==1){
        node*parent=findatpositionk(head,i-1);
        node*a =parent->next;
        parent->next=parent->next->next;
        node*b=parent->next->next;
        a->next=b;
        parent->next->next=a;


    }
    if(i==0){
        node*parent=findatpositionk(head,j-1);
        node*a=head;
        node*b=parent->next->next;
        head=parent->next;
        head->next=a->next;
        a->next=b;
        parent->next=a;
    }
    node*parent1=findatpositionk(head,i-1);
    node*parent2=findatpositionk(head,j-1);
    node*temp=parent1->next;
    node*a=parent1->next->next;
    node*b=parent2->next->next;
    parent1->next=parent2->next;
    parent1->next->next=a;
    temp->next=b;
    parent2->next=temp;

}
int main()
{
    int data;
    node*head=NULL;
    for(int i=0;i<6;i++){
        cin>>data;
        pushinlist(data,head);
    }
    /*int k;
    cout<<"enter k";

    cin>>k;
    deletekfromlast(k,head);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }*/
    /*int position;
    cout<<"enter the position";
    cin>>position;
    cin>>data;
    inserttkposition(head,data,position);*/

    //node * k=findatpositionk(head,0);
    //cout<<k->data;
    swapnode(head,1,4);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
