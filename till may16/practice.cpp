#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void insertbst(node*&root,int data){
    if(root==NULL){
        root=new node(data);
        return;
    }
    node*it=root;
    node*temp=new node(data);
    while(it){
        if(data<=it->data){
            if(it->left==NULL){
                it->left=temp;
                return;
            }
            it=it->left;
        }
        else{
            if(it->right==NULL){
                it->right=temp;
                return;
            }
            it=it->right;
        }
    }
}
void levelorder(node * root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(q.empty()!=1){
        node*top=q.front();
        q.pop();
        if(top->left!=NULL){
           q.push(top->left);
        }
        if(top->right!=NULL){
            q.push(top->right);
        }
        cout<<top->data<<" ";

    }
}
node*deletebst(node*&root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        root->left=deletebst(root->left,data);
        return root;
    }
    else if(root->data==data){
        //for no leaf node
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //for 1 leaf
        if(root->left!=NULL&&root->right==NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }

        //for 2 leaf
        if(root->right!=NULL&&root->right!=NULL){
            node*it=root->right;
            while(it->left!=NULL){
                it=it->left;
                if(it->left==NULL){
                    swap(root->data,it->data);
                    root->right=deletebst(root->right,data);
                    return root;
                }
            }

        }

    }
    else if(data>root->data){
        root->right=deletebst(root->right,data);
        return root;
    }

}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
int main()
{
    node*root=NULL;
    insertbst(root,5);
    insertbst(root,3);
    insertbst(root,8);
    insertbst(root,2);
    insertbst(root,4);
    insertbst(root,6);
    insertbst(root,10);
    insertbst(root,1);
    insertbst(root,7);
    insertbst(root,9);
    insertbst(root,12);
    levelorder(root);
    cout<<endl;
    deletebst(root,5);
    levelorder(root);
    cout<<endl;
    preorder(root);


}

