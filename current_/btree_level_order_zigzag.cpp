/*
LEVEL ORDER ( ZIGZAG , BINARY TREE)
Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on.
This means odd levels should get printed from left to right and even levels should be printed from right to left. Each level should be printed at a new line.


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest
the node exists and false suggests it is NULL.
EXAMPLE
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
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
///FUNCTON TO PRINT ZIG-ZAG ORDER
template<typename T>
void print_zigZag(node<T>*root){
    if(root==NULL){
        return;
    }

    stack<node<T>*>s1;//  TO PRINT FROM LEFT TO RIGHT
    stack<node<T>*>s2;// TO PRINT FROM RIGHT TO LEFT
    s1.push(root);
    while(!s1.empty()||!s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                node<T>*top=s1.top();
                s1.pop();
                cout<<top->data<<" ";
                if(top->left){
                    s2.push(top->left);
                }
                if(top->right){
                    s2.push(top->right);
                }
            }
        }
        else{
            while(!s2.empty()){
                node<T>*top=s2.top();
                s2.pop();
                cout<<top->data<<" ";
                if(top->right){
                    s1.push(top->right);
                }
                if(top->left){
                    s1.push(top->left);
                }
            }
        }
    }

}
int main()
{
    node<int>*root=NULL;
    root=createbtree<int>(root,1);
    print_zigZag<int>(root);
}
