#include<iostream>
using namespace std;
template<typename T>
struct node{
 T data;
 node<T>*next;

};
template<typename T>
struct stack{
    private:
        node<T>*head;
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
        int sizeofstack(){
            return size;
        }
        void push(T data){
          node<T>*temp=new node<T>;
          temp->data=data;
          temp->next=head;

          head=temp;
          size++;
        }
        void pop(){
         node<T>*it=head->next;
         head =head->next;
         delete it;
         --size;
         if(size==0){
            head=NULL;
         }
        }
        int top(){
            if(isempty()==true){
                return -1;
            }
            return head->data;
        }

};
int main()
{
    stack <char>s;
    char arr[100];
    cin.getline(arr,100);
    int i=0;
    while(arr[i]!=NULL){
            char t=s.top();
        if(arr[i]==t){
           s.pop();
        }
        else{
            s.push(arr[i]);
        }
        i++;
    }
    cout<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.top();
    if(s.isempty()==1){
        cout<<"stack is clear";
    }
    else{
        cout<<"not done";
    }


}
