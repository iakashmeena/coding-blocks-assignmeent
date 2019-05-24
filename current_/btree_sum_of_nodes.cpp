/*
SUM OF THE NODES (BINARY TREE)
Given a binary tree find sum of all the nodes.


Input Format:
Enter the value of the node then the Boolean choice i.e whether the node has a left child ,
then enter the left child's data . The input acts in a recursive manner i.e when the left
child's children are made only then we move onto the parent's right child
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
int nodeSum(node<T>*root){
    if(root==NULL){
        return 0;
    }
    int left_sum=nodeSum(root->left);
    int right_sum=nodeSum(root->right);
    return root->data+left_sum+right_sum;
}

int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root);
    cout<<nodeSum(root);

}
