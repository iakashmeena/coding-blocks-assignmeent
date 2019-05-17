#include<iostream>
using namespace std;
struct node{
 int data;
 node*next;

};

struct stack{
    private:
        node*head;
        int size;
    public:
         stack(){
         head=NULL;
         size=0;
        }
        bool isempty(){
            if(head==NULL){
                return 1;
            }
            return 0;

        }
        //size =0;
        int sizeofstack(){
            return size;
        }
        void push(int data){
          node*temp=new node;
          temp->data=data;
          temp->next=head;

          head=temp;
          size++;
        }
        void pop(){
         node*it=head->next;
         head =head->next;
         delete it;
         size--;
        }
        int top(){
            return head->data;
        }

};
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    cout<<s.sizeofstack()<<endl;
    s.pop();
    cout<<s.sizeofstack()<<endl;
    cout<<s.top();
}
