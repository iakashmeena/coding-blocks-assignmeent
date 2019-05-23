/*LARGEST BST IN A BINARY TREE
Given a Binary Tree, write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)


Input Format:
The first line of input will contain an integer n.
The next line will contain n integers denoting the the preorder traversal of the BT.
The next line will contain n more integers denoting the inorder traversal of the BT.
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node{
public:
       T data;
       node *left;
       node *right;
       node(T data){
            this->data=data;
            left=NULL;
            right=NULL;
       }

};
template<typename T>
int find_(T inorder[100],int i2,int j2,int k){
    for(int i=i2;i<=j2;i++){
        if(inorder[i]==k){
            return i;
        }
    }
}
///CREATE BST FROM PREORDER AND INORDER
template<typename T>
node<T>* createBtree(node<T>*&root,T preorder[],int i1,int j1,T inorder[],int i2,int j2){
    if(i1>j1){
        return NULL;
    }
    root=new node<T>(preorder[i1]);
    int index=find_(inorder,i2,j2,preorder[i1]);
    int l=index-i2;

    root->left=createBtree(root->left,preorder,i1+1,i1+l,inorder,i2,index-1);//ending point of preorder has to be restricted after i1+(it-i2)
    root->right=createBtree(root->right,preorder,i1+l+1,j1,inorder,index+1,j2);//starting point of preorder has to be shifted i1+1+(no. of element before preorder[i1] in inorder)
    return root;
}

///TO FIND IF THE GIVEN ROOT IS THE ROOT OF A BST
template<typename T>
bool isBst(node<T>*root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    bool oky1=true;
    bool oky2=true;
    bool left_is_bst=isBst(root->left);
    bool right_is_bst=isBst(root->right);
    if(root->left){
        if(root->left->data>root->data){
            oky1=false;
        }
    }
    if(root->right){
        if(root->right->data<root->data){
            oky2=false;
        }
    }
    if(left_is_bst&&right_is_bst&&oky1&&oky2){
        return true;
    }
    return false;
}
///COUNT NUMBER OF TREE IN A BINARE TREE
template<typename T>
int countNodes(node<T>*root){
    if(root==NULL){
        return 0;
    }
    int count_for_left=countNodes(root->left);
    int count_for_right=countNodes(root->right);
    return count_for_left+count_for_right+1;
}
///COUNT OF ELEMENT IN MAX BST
template<typename T>
int countMax_bst(node<T>*root,int n){
    if(root==NULL){
        return 0;
    }
    if(isBst(root)){
        int count_nodes_=countNodes(root);
        if(n<count_nodes_){
            return count_nodes_;
        }
    }
    int maxBst_left=countMax_bst(root->left,n);
    int maxBst_right=countMax_bst(root->right,n);
    return max(maxBst_left,maxBst_right);
}


int main()
{
    node<int>*root=NULL;
    int preorder[1000];
    int inorder[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    root=createBtree<int>(root,preorder,0,n-1,inorder,0,n-1);
    cout<<countMax_bst<int>(root,INT_MIN);
}
