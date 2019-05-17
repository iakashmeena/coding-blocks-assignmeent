#include<iostream>
#include<queue>
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
node*createbtree(){
    node*root=NULL;
    queue<node*>q;
    int data;
    cout<<"enter the root"<<endl;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(q.empty()==0){
        node *it=q.front();
        q.pop();

        cout<<"left data for "<<it->data<<endl;
        cin>>data;
        if(data!=-1){
            node*left=new node(data);
            it->left=left;
            q.push(left);
        }

        cout<<"right data for "<<it->data<<endl;
        cin>>data;
        if(data!=-1){
            node*right=new node(data);
            it->right=right;
            q.push(right);
        }

    }

    return root;

}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
int nodecount(node*root){
    if(root==NULL){
        return 0;
    }
    int x=nodecount(root->left);
    int y=nodecount(root->right);
    return x+y+1;
}
int max(int &a,int&b){
    if(a>b){
        return a;
    }
    return b;
}
int maxdigit(node*root){
    if(root==NULL){
        return -999999;
    }
    int left=maxdigit(root->left);
    int right=maxdigit(root->right);
    int m=max(left,right);
    return max(m,root->data);

}
int countgreater(node*root,int x){
    if(root==NULL){
        return 0;
    }
    int left=countgreater(root->left,x);
    int right=countgreater(root->right,x);
    if(root->data>x){
        return left+right+1;
    }
}
pair<node *,int> maxPair(pair<node *,int> a,pair<node *,int> b){
    if(a.second > b.second){
        return a;
    }else{
        return b;
    }
}
pair<node *,int> maxGroup(node * root){
    if(root==NULL){
        pair<node *,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<node *,int> left = maxGroup(root->left);
    pair<node *,int> right = maxGroup(root->right);
    pair<node *,int> max = maxPair(left,right);
    int grp = root->data;
    if(root->left){
        grp+=root->left->data;
    }
    if(root->right){
        grp+=root->right->data;
    }
    if(grp>max.second){
        pair<node *,int> p;
        p.first = root;
        p.second = grp;
        return p;
    }
    return max;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
   // return max(m,m)+1;
}
int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int a=left+right;
    int b=diameter(root->left);
    int c=diameter(root->right);
    return max(max(a,b),c);
}
class par{
public:
    int height;
    int diameter;

};
par fastdiameter(node*root){
    par p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    par left=fastdiameter(root->left);
    par right=fastdiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}
node * mirror(node*root){
    if(root==NULL){
        return NULL;
    }
    node*temp=new node(root->data);
    temp->right=mirror(root->left);
    temp->left=mirror(root->right);
    return temp;
}
int find(int in[],int instart,int inend,int d){
    for(int i=instart;i<=inend;i++){
        if(in[i]==d){
            return i;
        }
    }
    return -1;
}
node*treefrompreandin(int pre[100],int prestart,int preend,int in[100],int instart,int inend){
    if(prestart>preend){
        return NULL;
    }
    int rootData = pre[prestart];
    int i=find(in,instart,inend,rootData);
    int l=i-instart;
    int r=inend-i;
    node*root=new node(rootData);
    root->left=treefrompreandin(pre,prestart+1,prestart+l,in,instart,i-1);
    root->right=treefrompreandin(pre,prestart+l+1,preend,in,i+1,inend);
    return root;

}

//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9 -1 -1 -1 -1
int main()
{/*
    node*root=NULL;
    root=createbtree();
    levelorder(root);
    cout<<endl;
    cout<<"nodecount "<<nodecount(root)<<endl;
    cout<<"maxdigit "<<maxdigit(root)<<endl;
    cout<<"count greater"<<countgreater(root,0)<<endl;
    pair<node*,int>p=maxGroup(root);
    cout<<p.first->data<<endl;
    cout<<p.second<<endl;
    cout<<"height"<<height(root)<<endl;
    cout<<"diameter"<<diameter(root)<<endl;
    par q=fastdiameter(root);
    cout<<"fastdiameter"<<q.diameter<<endl;
    node*mirrorroot=mirror(root);
    levelorder(mirrorroot);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;*/
    int in[]={4,2,5,1,6,3,8,7,9};
    int pre[]={1,2,4,5,3,6,7,8,9};
    node*ro=treefrompreandin(pre,0,8,in,0,8);
    inorder(ro);
}
