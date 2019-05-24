/*
SIBLING ( BINARY TREE)
Given a binary tree print all nodes that don’t have a sibling


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest
the node exists and false suggests it is NULL
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
node<T>* createbtree(node<T>*root,bool want_to_insert=1){
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
template<typename T>
void nodesNot_siblings(node<T>*root){
    if(root==NULL){
        return;
    }
    if(root->right&&root->left){
        nodesNot_siblings(root->left);
        nodesNot_siblings(root->right);
    }
    else if(root->left!=NULL&&root->right==NULL){

        cout<<root->left->data<<" ";
        nodesNot_siblings(root->left);
    }

    else if(root->left==NULL&&root->right!=NULL){

        cout<<root->right->data<<" ";
        nodesNot_siblings(root->right);
    }

    return;
}

int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root,1);
    nodesNot_siblings<int>(root);
}
