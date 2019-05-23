/*
IS BALANCED (BINARY TREE)
Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
*/

#include<bits/stdc++.h>
using namespace std;
template<typename  T>
class node{
public:
    T data;
    node*left;
    node*right;
    node(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
///BIANRY TREE CREATION
///RECURSIVELY
template<typename T>
node<T>* buildtree(node<T>*root,bool want_to_enter){
    if(want_to_enter==false){
        return NULL;
    }
    T data;
    cin>>data;
    root=new node<T>(data);
    string s;//TO EXCEPT VALUE IN FORM OF STRING
    ///FOR LEFT
    cin>>s;
    if(s[0]=='f'){
        want_to_enter=false;
    }
    else if(s[0]=='t'){
        want_to_enter=true;
    }
    if(want_to_enter==true){
        root->left=buildtree(root->left,want_to_enter);
    }

    /// FOR RIGHT
    cin>>s;
    if(s[0]=='f'){
        want_to_enter=false;
    }
    else if(s[0]=='t'){
        want_to_enter=true;
    }
    if(want_to_enter==true){
        root->right=buildtree(root->right,want_to_enter);
    }
    return root;
}
int max(int &a,int &b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
///RECURSIVE FUNCTION TO FIND HEIGHT
template<typename T>
int height(node<T>*root){
    if(root==NULL){
        return 0;
    }
    int find_height_of_left_subtree=height(root->left);
    int find_height_of_right_subtree=height(root->right);

    return max(find_height_of_left_subtree,find_height_of_right_subtree)+1;
}
///RECURSIVE FUNCTION TO FIND IF THE TREE IS BALANCED
///A TREE IS BALANCED IF DIFFERENCE OF HEIGHT OF LEFT SUBTREE AND RIGHT SUBTREE IS ATMOST ONT
template<typename T>
bool is_balance(node<T>*root){
    if(root==NULL){
        return true;
    }
    bool tell_if_left_subtree_is_balanced=is_balance(root->left);
    if(tell_if_left_subtree_is_balanced==false){
        return false;
    }
    bool tell_if_right_subtree_is_balanced=is_balance(root->right);
    if(tell_if_right_subtree_is_balanced==false){
        return false;
    }

    if(abs(height(root->left)-height(root->right))<=1){
        return true;
    }
    return false;


}
template<typename T>
void preorder(node<T>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    return;
}

int main()
{
    node<int>*root=NULL;
    root=buildtree<int>(root,1);
    preorder(root);
    /*if(is_balance<int>(root)==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }*/
}
