/*
ROOT TO LEAF ( BINARY TREE)
Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number.

Input Format:
First line contains the values of all the nodes in the binary tree in pre-order format where true suggest the node
exists and false suggests it is NULL.
Second line contains the number k.


10 true 40 true 60 false false true 50 false false true 20 true 30 false false true 73 false false
60

Output Format:
Display the root to leaf path whose sum is equal to k.

*/


#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node{
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
///creation of binary tree

template<typename T>
node<T>* createbtree(node<T>*root,bool want_to_insert){
    if(want_to_insert==false){
        return NULL;
    }

    T data;
    string check;
    cin>>data;
    root=new node<T>(data);
    ///left data insertion
    cin>>check;
    if(check[0]=='t'||check[0]=='T'){
        want_to_insert=true;
    }
    if(check[0]=='f'||check[0]=='F'){
        want_to_insert=false;
    }

    if(want_to_insert==true){
        root->left=createbtree(root->left,want_to_insert);
    }


    ///right data
    cin>>check;
    if(check[0]=='t'||check[0]=='T'){
        want_to_insert=true;
    }
    if(check[0]=='f'||check[0]=='F'){
        want_to_insert=false;
    }

    if(want_to_insert==true){
        root->right=createbtree(root->right,want_to_insert);
    }

    return root;
}
int sum=0;//GLOBAL VERIABLE

template<typename T>
void sumOf_nodes(node<T>*root,T k,stack<T>&q){
    if(root==NULL){
        return;
    }
    sum=sum+root->data;
    q.push(root->data);
    if(root->left==NULL&&root->right==NULL){
        if(sum==k){
            return;
        }
        else{
            sum=sum-q.top();
            q.pop();
            return;
        }
    }
    /// INORDER TRAVESAL IS USED
    sumOf_nodes(root->left,k,q);
    if(sum==k){
        return;
    }
    sumOf_nodes(root->right,k,q);
    if(sum!=k){
        sum=sum-q.top();
        q.pop();
    }

}
template<typename T>
void insert_at_bottom(stack<T>&s,int top){
    if(s.empty()){
        s.push(top);
        return;
    }
    int temp;
    temp=s.top();
    s.pop();
    insert_at_bottom(s,top);
    s.push(temp);
}
template<typename T>
void reverseStack(stack<T>&s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    reverseStack(s);
    insert_at_bottom(s,top);
}
int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root,1);
    stack<int>q;
    int k;
    cin>>k;
    sumOf_nodes(root,k,q);
    reverseStack(q);
    while(!q.empty()){
        //node<int>*top=q.front();
       cout<<q.top()<<" ";
       q.pop();
    }

}
