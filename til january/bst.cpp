#include<iostream>
#include<queue>
#include<math.h>
#include<climits>
#include<cstdlib>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    node(int data){
    this->data = data;
    left = right = NULL;
    }
};
void addElement(node ** root,int data){
    if(*root==NULL){
        *root = new node(data);
        return;
    }
    node * temp = new node(data);
    node * it = *root;
    while(it!=NULL){
        if(it->data<data){
            if(it->right==NULL){
                it->right = temp;
                return;
            }
            it = it->right;
        }else{
            if(it->left==NULL){
                it->left = temp;
                return;
            }
            it = it->left;
        }
    }
}
void levelorder(node * root){
    queue<node *>q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        node * temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        q.pop();
    }
}/*
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    return;
}*/
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
    return;
}
void inorder(node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    return;
}
/* preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}*/
int height(node * root){
    if(!root){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
bool isballancebst(node*root){
    if(root==NULL){
        return 1;
    }
    bool l=isbst(root->left);
    bool k=isbst(root->right);
    int left=height(root->left);
    int right=height(root->right);
    bool x=false;
    if(abs(left-right)<=1){
        x=true;
    }
    return x&l&k;


}
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
pair<bool,int> bool(node*root){
    if(root==NULL){
        pair<bool,int> p;
        p.fist=1;
        p.seco.
        nd
    }
}

int main(){
node * root = NULL;
addElement(&root,5);
addElement(&root,3);
addElement(&root,8);
addElement(&root,1);
addElement(&root,7);
addElement(&root,10);
addElement(&root,4);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
addElement(&root,5);
cout<<endl<<isbst(root);
}
