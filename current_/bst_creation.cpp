/*
BUILD BST
You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.


Input Format:
First line contains integer t as number of test cases. Each test case contains following input.
First line contains integer n which represents
the length of the data and next line contains n space separated integers.

*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class  node{
public:
    T data;
    node* left;
    node*right;
    node(T data){
       this->data=data;
       left=NULL;
       right=NULL;
    }

};

template<typename T>
void insert_in_bst(node<T>*&root,T data){
    node<T>*temp=new node<T>(data);
    if(root==NULL){
        root=temp;
        return;
    }
    node<T>*it=root;
    while(it){
        if(it->data<data){
            if(it->right==NULL){
                it->right=temp;
                return;
            }
            it=it->right;
        }
        else{
            if(it->left==NULL){
                it->left=temp;
                return;
            }
            it=it->left;
        }
    }
    return;
}


template<typename T>
node<T>*createBalnace_bst(node<T>*&root,int arr[100],int start,int end_){
    if(start>end_){
        return NULL;
    }
    int mid=(start+end_)/2;
    node<T>*temp=new node<T>(arr[mid]);
    root=temp;
    root->left=createBalnace_bst(root->left,arr,start,mid-1);
    root->right=createBalnace_bst(root->right,arr,mid+1,end_);
    return root;
}
template<typename T>
void preorder(node<T>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{

   int t;
   cin>>t;
   while(t--){
         node<int> *root=NULL;
        int n;
        cin>>n;
        int arr[1000];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        root=createBalnace_bst(root,arr,0,n-1);
        preorder(root);

   }
}
