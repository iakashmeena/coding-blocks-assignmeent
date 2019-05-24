/*
LOWEST COMMON ANCESTOR (BINARY TREE )
Find LCA(Lowest Common Ancestor) of two elements in a Binary Tree.


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where
true suggest the node exists and false suggests it is NULL

Sample Input:

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
50
60

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

template<typename T>
node<T>* lowComman_ancestor(node<T>*root,T n1,T n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node<T>*left_comman_ancestor=lowComman_ancestor(root->left,n1,n2);
    node<T>*right_comman_ancestor=lowComman_ancestor(root->right,n1,n2);

///THIS CONDITION WILL CHECK IF ONE NUMBER IS AT LEFT AND ANOTHER IS AT RIGHT
    if(left_comman_ancestor!=NULL && right_comman_ancestor!=NULL){
        return root;
    }
///THIS CONDITION WILL CHECK IF BOTH ARE PRESENT ONLY AT LEFT (STRICTLY LEFT)
    if(left_comman_ancestor!=NULL && right_comman_ancestor==NULL){
        return left_comman_ancestor;
    }
///THIS CONDITION WILL CHECK IF BOTH ARE PRESENT ONLY AT RIGHT (STRICTLY RIGHT)
    if(left_comman_ancestor==NULL && right_comman_ancestor!=NULL){
        return right_comman_ancestor;
    }
}
int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root,1);
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    cout<<lowComman_ancestor(root,n1,n2)->data;
}
