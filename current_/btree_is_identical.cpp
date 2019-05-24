/*
STRUCTURALLY IDENTICAL (BINARY TREE)
Given two trees check if they are structurally identically


Input Format:
Enter the values of all the nodes in the binary tree in
pre-order format where true suggest the node exists and false suggests it is NULL
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
bool isIdentical(node<T>*root1,node<T>*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL&&root2!=NULL){
        return false;
    }
    if(root1!=NULL&&root2==NULL){
        return false;
    }

    if(root1->data==root2->data){
        bool left_identical=isIdentical(root1->left,root2->left);
        if(left_identical==false){
            return false;
        }
        bool right_identical=isIdentical(root1->right,root2->right);
        return left_identical&&right_identical;
    }

    return false;
}
int main()
{
    node<int>*root1=NULL;
    root1=createbtree<int>(root1,1);
    node<int>*root2=NULL;
    root2=createbtree<int>(root2,1);
    if(isIdentical(root1,root2)==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

}
