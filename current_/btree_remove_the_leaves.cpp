/*
REMOVE THE LEAVES ( BINARY TREE )
Given a binary tree, remove all the leaves from the tree


Input Format:
Enter the value of the nodes of the tree,in preorder format.

Output Format:
Display the tree in which all the leaves have been removed in pre-order traversal in the following format :
Left->data => Root->data <= Right->Data
Output END if left or right node is NULL
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
node<T>*removeLeaf(node<T>*&root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        delete root->left;
        return NULL;
    }
    root->left=removeLeaf(root->left);
    root->right=removeLeaf(root->right);
    return root;
}
template<typename T>
void preorder(node<T>*root){
    if(root==NULL){
        return;
    }
    if(root->left){
        cout<<root->left->data<<" => ";
    }
    else{
        cout<<"END => ";
    }
    cout<<root->data;

    if(root->right){
        cout<<" <= "<<root->right->data;
    }
    else{
        cout<<" <= END";
    }
    cout<<endl;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node<int>*root=NULL;
    root=createbtree(root,1);
    root=removeLeaf<int>(root);
    preorder(root);
}
