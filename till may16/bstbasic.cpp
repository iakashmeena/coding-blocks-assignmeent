#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void bstinsert(node*&root,int data){
    if(root==NULL){
        root=new node(data);
        return;
    }
    node*temp=new node(data);
    node *it=root;
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
void levelorder(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(q.empty()==0){
        node*it=q.front();
        q.pop();
        cout<<it->data;
        if(it->left){
            q.push(it->left);
        }
        if(it->right){
            q.push(it->right);
        }
    }
}
bool find(node*root,int data){
    if(root==NULL){
        return false;
    }
    while(root){
        if(root->data==data){
            return true;
        }
        if(root->data<data){
            root=root->right;
        }
        else {
            root=root->left;
        }
    }
    return false;
}
node*deleteelement(node*&root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        root->left=deleteelement(root->left,data);
        return root;
    }
    else if(data==root->data){
        //for 0 children leaf
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //for 1 children leaf
        if(root->left==NULL&&root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL&&root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        //for 2 children leaf
       /* node*parent=root;
        node*it=root->right;
        if(it->left==NULL){
            it->left=root->left;
            delete root;
            return it;
        }
        if(it->left){
            while(it->left!=NULL){
                it=it->left;
            }
            root->data=it->data;
        }*/

        node*replace=root->right;
        if(replace->left==NULL){
            swap(root->data,replace->data);
            root->right=deleteelement(root->right,data);
            return root;

        }
        while(replace->left!=NULL){
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deleteelement(root->right,replace->data);
        return root;

    }
    else if(data>root->data){
        root->right=deleteelement(root->right,data);
        return root;
    }
    //return root;
}
int max(int &a,int&b){
    if(a>b){
        return a;
    }
    return b;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
bool checkisbalanced(node*root){
    if(root==NULL){
        return true;
    }
    bool lefttrue=checkisbalanced(root->left);
    bool rightrue=checkisbalanced(root->right);
    int lh=height(root->left);
    int rh=height(root->right);

    bool x=false;
    if(abs(lh-rh)<=1){
        x=true;
    }
    return lefttrue&rightrue&x;
}
class par{
public:
    int height;
    bool balanced;
};
par fastbalanced(node*root){
    par p;
    if(root==NULL){
        p.height=0;
        p.balanced=1;
        return p;
    }
    par lh=fastbalanced(root->left);
    par rh=fastbalanced(root->right);
    p.height=max(lh.height,rh.height)+1;
    bool x=false;
    if(abs(lh.height-rh.height)<=1){
        x=true;
    }
    if(x&lh.balanced&rh.balanced){
        p.balanced=true;
        return p;
    }
    else{
        p.balanced=false;
        return p;
    }

}
pair<bool,pair<int,int> > isbst(node*root){
    pair<bool,pair<int,int> > p;
    if(root==NULL){
        p.first=true;
        p.second.first=INT_MAX;
        p.second.second=INT_MIN;
        return p;
    }
    pair<bool,pair<int,int> >left=isbst(root->left);
    pair<bool,pair<int,int> >right=isbst(root->right);
    bool x=false;
    if(root->data>=left.second.second&&root->data<right.second.first){
        x=true;
    }
    if(left.first&right.first&x){
        p.first=true;
    }
    p.second.first=min(left.second.first,root->data);
    p.second.second=max(left.second.second,root->data);
    return p;

}
int main()
{
    node*root=NULL;
    bstinsert(root,5);
    bstinsert(root,2);
    bstinsert(root,9);
    bstinsert(root,1);
    bstinsert(root,3);
    bstinsert(root,4);
    bstinsert(root,7);
    bstinsert(root,8);
    bstinsert(root,10);
    levelorder(root);
    cout<<endl;
    cout<<find(root,10);
    cout<<endl;
    /*node*afterdelete=deleteelement(root,5);
    levelorder(afterdelete);
    cout<<endl;*/
    cout<<"isbalnced slow "<<checkisbalanced(root);
    cout<<endl;
    par p=fastbalanced(root);
    cout<<"isbalanced fast "<<p.balanced;
    cout<<endl;
    pair<bool,pair<int,int> >q=isbst(root);
    cout<<"check is bst "<<q.first;
    cout<<endl;

}
