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
node * createlinklist(int n){
    if(n<=0){
        return NULL;
    }
    int data;
    cin>>data;
    node*head=new node(data);
    --n;
    node*it=head;
    while(n){
        cin>>data;
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        --n;
    }

    return head;
}

//arrange in odd even
void arrange(node*head,int n){
    if(head==NULL){
        return;
    }
    node*it=head;
    node*even=head->next;
        node*even1=even;
        while(even1->next!=NULL){
           even1=it->next;
          //terminating condition if the no. of nodes are even
           if(even1->next==NULL){
            it->next=even;
            return;
           }

           it->next=it->next->next;
           it=it->next;

           if(it->next!=NULL){
              even1->next=it->next;
           }

           else{

            it->next=even;
            even1->next=NULL;
           }

        }

    }


int main()
{
    int n;
    cin>>n;
    node* head=createlinklist(n);
    arrange(head,n);
    node*it=head;
    while(it){
        cout<<it->data<<" ";
        it=it->next;
    }
}
