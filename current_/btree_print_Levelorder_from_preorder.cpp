/*
LEVEL ORDER ( NEW LINE, BINARY TREE)
input type preorder value

EXAMPLE
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Given a binary tree. Print the level order traversal, make sure each level start at a new line.
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

///level order printing

template<typename T>
void printLevelorder(node<T>*root){
    if(root==NULL){
        return;
    }
    queue<node<T>*>q1;
    queue<node<T>*>q2;
    q1.push(root);
    while(q1.empty()==0||q2.empty()==0){
        if(!q1.empty()){
            while(!q1.empty()){
                node<T>*top=q1.front();
                q1.pop();
                cout<<top->data<<" ";
                if(top->left){
                    q2.push(top->left);
                }
                if(top->right){
                    q2.push(top->right);
                }
            }
        }
        else{
            while(!q2.empty()){
                node<T>*top=q2.front();
                q2.pop();
                cout<<top->data<<" ";
                if(top->left){
                    q1.push(top->left);
                }
                if(top->right){
                    q1.push(top->right);
                }

            }
        }
        cout<<endl;
    }
}

int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root,1);
    printLevelorder<int>(root);
}






