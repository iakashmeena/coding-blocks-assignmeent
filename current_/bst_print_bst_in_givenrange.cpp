/*
PRINT BST KEYS IN THE GIVEN RANGE
You are given an array of integers. First of all ,
You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2.
You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).


Input Format:
First line contains integer t as number of test cases. Each test case contains three lines.
First line contains an integer n which is length of the array and second line contains n space separated integer.
Third line contains the value of k1 and k2.

Output Format:
For each test case you have to print preorder traversal of the tree first and
then print all nodes within the range k1 and k2 (inclusive).


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
void insert_in_Bst(node<T>*&root,T data){
    if(root==NULL){
        root=new node<T>(data);
        return;
    }
    node<T>*temp=new node<T>(data);
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
///SAME FUNCTION TO PRINT ORDER AND PUSH OBJECTS IN SET
template<typename T>
void preorder(node<T>*root,set<T> &s,int k1,int k2){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->data>=k1 && root->data<=k2){
        s.insert(root->data);
    }
    preorder(root->left,s,k1,k2);
    preorder(root->right,s,k1,k2);
    return;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        node<int>* root=NULL;
        int n;
        cin>>n;
        while(n--){
            int number;
            cin>>number;
            insert_in_Bst<int>(root,number);
        }
        set<int> s;
        int k1;
        int k2;
        cin>>k1>>k2;
        cout<<"# Preorder : ";
        preorder(root,s,k1,k2);
        cout<<endl;
        cout<<"# Nodes within range are : ";
        for(auto it:s){
            cout<<it<<" ";
        }
    }

}
