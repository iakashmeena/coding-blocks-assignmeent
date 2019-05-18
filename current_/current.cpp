/*
FIND SUM AT LEVEL K
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class node{
public:
    T data;
    node * left;
    node * right;
    node(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
///create binary tree
template<typename T>
node<T>*buildtree(){
    node<T>* root;
    queue<node<T>*> q;
    T data;
    cin>>data;
    root=new node<T>(data);
    q.push(root);
    while(!q.empty()){
        node<T>*top=q.front();
        q.pop();
        cin>>data;
        ///if data -1 left/right ==NULL
        if(data!=-1){
            top->left=new node<T>(data);
            q.push(top->left);
        }
        cin>>data;
        if(data!=-1){
            top->right=new node<T>(data);
            q.push(top->right);
        }
    }
    return root;
}

///function to find sum of nodes at level k

template<typename T>
int sum_At_level_k(int k,node<T>*root){
    if(root==NULL){
        return -1;
    }
    queue<node<T>*>q1;
    queue<node<T>*>q2;
    q1.push(root);
    while(--k){
        if(!q1.empty()){
            while(!q1.empty()){
                node<T>*top=q1.front();
                q1.pop();
                if(top->left){
                    q2.push(top->left);
                }
                if(top->right){
                    q2.push(top->right);
                }
            }
        }
        else {
            while(!q2.empty()){
                node<T>*top=q2.front();
                q2.pop();
                if(top->left){
                    q1.push(top->left);
                }
                if(top->right){
                    q1.push(top->right);
                }
            }
        }

    }
    int sum=0;
    while(!q1.empty()){
        node<T>*top=q1.front();
        T current=top->data;
        sum=sum + current;
        q1.pop();
    }
    while(!q2.empty()){
        node<T>*top=q2.front();
        T current=top->data;
        sum=sum + current;
        q2.pop();
    }
    return sum;
}
///  1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    node<int>*root=buildtree<int>();
    int k;
    cin>>k;
    cout<<sum_At_level_k(k,root);

}
