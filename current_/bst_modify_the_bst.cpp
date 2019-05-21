/*MODIFIED THE BST PART - 2
You are given an array of integers. First of all , You have to form a binary search tree from given integers.
Now you have given a range. You need to remove all nodes of the BST which are outside the given range.

Input Format:
First line contains integer t as number of test cases. Each test case contains third lines.
First line contains an integer n which is length of the array and second line contains n space separated integer.
Third lines contains the range.

Output Format:
For each test case you have to print preorder traversal of the original tree as well as modified tree.
*/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
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
void inserinBst(node<T>*&root,T data){
    node<T>*temp=new node<T>(data);
    if(root==NULL){
        root=temp;
        return;
    }
    node<T>*it=root;
    while(it!=NULL){
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
}

template<typename T>
node<T>* delete_node_inBst(node<T>*&root,T data){
    if(root==NULL){
        return NULL;
    }
    if(root->data>data){
        root->left=delete_node_inBst(root->left,data);
        return root;
    }
    else if(root->data==data){
        ///FOR ZERO CHILDEREN
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        ///FOR ONE CHILDEREN
        if(root->left==NULL&&root->right!=NULL){
            node<T>*it=root->right;
            delete root;
            return it;
        }

        if(root->left!=NULL&&root->right==NULL){
            node<T>*it=root->left;
            delete root;
            return it;
        }
        /// FOR TWO CHILDEREN
        node<T>*replace=root->right;
        if(replace->left==NULL){
            swap(root->data,replace->data);
            root->right=delete_node_inBst(root->right,data);
            return root;
        }
        while(replace->left!=NULL){
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=delete_node_inBst(root->right,replace->data);
        return root;
    }
    else{
        root->right=delete_node_inBst(root->right,data);
        return root;
    }
}

template<typename T>
void preorder(node<T>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

template<typename T>
void set_in_range(node<T>*&root,set<T>&s,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data<k1){
        s.insert(root->data);
    }
    if(root->data>k2){
        s.insert(root->data);
    }
    set_in_range(root->left,s,k1,k2);
    set_in_range(root->right,s,k1,k2);

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        node<int>*root=NULL;
        int n;
        set<int>s;//CAN'T DELETE IN A RECURSIVE FUNCTION SO DELETE ONE BY ONE AFTER PUTTING DESIRED VALUE IN ANY DATA STRUCTURE
        cin>>n;
            while(n--){
            int data;
            cin>>data;
            inserinBst<int>(root,data);
            }

        cout<<"Preorder : ";
        preorder<int>(root);
        cout<<endl;

        int k1;
        int k2;
        cin>>k1>>k2;
        set_in_range(root,s,k1,k2);
        for(auto it:s){
            root=delete_node_inBst(root,it);
        }

        cout<<"Preorder : ";
        preorder<int>(root);
    }

}
