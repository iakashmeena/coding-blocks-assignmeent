#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct node{
public:

    T data;
    node* left;
    node* right;
    node(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
template<typename T>
node <T>* createbtree(){
    node<T>*root=NULL;
    queue<node<T>*> q;
    T data;
    cin>>data;
    node<T>*temp=new node<T>(data);
    root=temp;
    q.push(root);
    while(!q.empty()){
        node<T> *top=q.front();
        q.pop();
        ///left node data (null for -1)
        cin>>data;
        if(data!=-1){
            top->left=new node<T>(data);
            q.push(temp);
        }
        ///right node data
        cin>>data;
        if(data!=-1){
            top->right=new node<T>(data);
            q.push(temp);
        }
    }
    return root;
}
template<typename T>
void inorder(node<T>*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" " ;
    inorder(root->right);
}
int main()
{

    node <int>*root=NULL;
    root=createbtree<int>();
   // inorder(root);

}

