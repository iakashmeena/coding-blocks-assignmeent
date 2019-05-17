#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
    node(int data){
        this->data =data;
        next=NULL;
    }
};
node*createll(int n){
    if(n==0){
        return NULL;
    }
    int data;
    cin>>data;
    node * head;
    node * temp=new node(data);
    if(n==1){
        head->data;
        return head;
    }
    node*it;
    head=temp;
    it=head;
    for(int i=1;i<n;i++){
        cin>>data;
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
    }
    return head;

}
void sortll(node* head,int n){
    if(head==NULL||n==0){
        return;
    }
    node*it=head;
    for(int i=n;i>1;i++){
        if(it->data>it->next->data){{
            node* temp=it;
            it=it->next;
            temp->next=it->next;
            it->next=temp;
            }

        }

    }
    sortll(head,n-1);
}

int main ()
{
    int n;
    cin>>n;
    node*head=createll(n);
    sortll(head,n);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }


}
