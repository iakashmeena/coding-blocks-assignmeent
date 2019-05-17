#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    int depth =0;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};
node * createBtree(){
    cout<<"Enter data and -1 if empty "<<endl;
    int data;
    cin>>data;
    node * root;
   if(data!=-1){
      root = new node(data);
    }
    queue<node * >q;
    q.push(root);
    while(!q.empty()){
        node * top = q.front();
        q.pop();
        cout<<"enter left data for "<< top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * left = new node(data);
            top->left = left;
            q.push(left);
        }
        cout<<"enter right data for "<< top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * right = new node(data);
            top->right = right;
            q.push(right);
        }
    }
    return root;
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
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void inorder(node * root){
    if(root==NULL){
            return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void levelorder(node * root){
    queue<node *>q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        node * top = q.front();
        cout<<top->data<<" ";
        q.pop();
        if(top->left){
           q.push(top->left);
        }
        if(top->right){
            q.push(top->right);
        }
    }
}
int nodeCount(node * root){
    if(root==NULL){
        return 0;
    }
    int left = nodeCount(root->left);
    int right = nodeCount(root->right);
    return left+right+1;
}
int max(int a ,int b){
    if(a>b){
        return a;
    }
    return b;
}
int largestNode(node * root){
    if(root==NULL){
        return INT_MIN;
    }
    int left = largestNode(root->left);
    int right = largestNode(root->right);
    int m = max(left,right);
    return max(m,root->data);
}

int countGreater(node * root,int x){
    if(root==NULL){
        return 0;
    }
    int left = countGreater(root->left,x);
    int right = countGreater(root->right,x);
    if(root->data > x){
        return left+right+1;
    }
    return left+right;
}
/*
pair<node *,int> maxPair(pair<node *,int> a,pair<node *,int> b){
    pair<node *,int> p;
    if(a.second > b.second){
        p.first = a.first;
        p.second = a.second;
    }else{
        p.first = b.first;
        p.second = b.second;
    }
    return p;
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
node * maxGroup1(node * root){
    if(root==NULL){
        return NULL;
    }
    node * left = maxGroup1(root->left);
    node * right = maxGroup1(root->right);
    int grpl = left->data;
    if(left->left){
        grpl+=left->left->data;
    }
    if(left->right){
        grpr+=left->right->data;
    }
    int grpr = right->data;
    if(left->left){
        grpr+=right->left->data;
    }
    if(left->right){
        grpr+=right->right->data;
    }
    int grp = root->data;
    if(root->left){
        grp+=root->left->data;
    }
    if(root->right){
        grp+=root->right->data;
    }
    if(grpl>grpr){
        if(grpl>grp){
            return left;
        }else{
            return root;
        }
    }else{
        if(grpr>grp){
            return right
        }else{
            return root;
        }
    }
}*/
void printatkdepth(node*root,int k){
    if(root==NULL){
        return;
    }
    queue<node*> q1;
    queue<node*> q2;
    q1.push(root);
    while(k--){
        while(q1.front()!=NULL){
            q2.push(q1.front()->left);
            q2.push(q1.front()->right);
            q1.pop();
        }
        while(q2.front()!=NULL){
            q1.push(q2.front());
            q2.pop();
        }

    }
    while(q1.front()!=NULL){
        cout<<q1.front()->data<<" ";
        q1.pop();
    }


}


bool ispresent(node*root,int n){
    if(root==NULL){
        return 0;
    }
    if(root->data==n){
        return 1;
    }

    bool k=ispresent(root->left,n);
    bool p=ispresent(root->right,n);
    if(k==1||p==1){
        return 1;
    }

    else {
        return 0;
    }
   /* if(root->data==n){
        return 1;
    }
    else {
        return 0;
    }*/
}




//1 2 3 -1 -1 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int degree(node* root){
    if(root==NULL){
        return 0;
    }

    int degree=0;
    if(root->left!=NULL){
       degree++;
    }
    if(root->right!=NULL){
        degree++;
    }
    return degree;
}
node* createmirror(node*root){
    if(root==NULL){
        return 0 ;
    }
    node*temp=new node(root->data);
    temp->right=createmirror(root->left);
    temp->left=createmirror(root->right);
    return temp;
}
/*
node* createtree(vector<int>post,int pstart,int pend,vector<int>in,int istart,int iend ){
    if(pend<pstart){
        return NULL;
    }
    int rootdata=post[pend];
    int index=find(in,istart,iend,rootdata);
    int l=index-istart;
    int r=iend-index;
    node*root=new node(rootdata);
    root->left=createtree(pre,pstart+l,pstar-l,in,istart,iend-1);
    root->right=createtree(pre,pstart+l,pstar-l,in,istart,iend-1);
    return root;

}*/
void addelement(node root,int data){
    if(root==NULL){

    }
}
void find(node*root,int data){
    if(head->data==data){
        return 1;
    }
    else if()
}
// 1 2 3 4 6 5 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 7 6 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
node * root = createBtree();
/*preorder(root);
cout<<endl;
postorder(root);
cout<<endl;
inorder(root);
cout<<endl;
levelorder(root);
cout<<endl;
cout<<nodeCount(root)<<endl;
cout<<largestNode(root)<<endl;
pair<node* ,int> p = maxGroup(root);
cout<<p.first->data<<" "<<p.second<<endl;*/
//cout<<degree(root);
//printatkdepth(root,3);
//cout<<ispresent(root,115);
/*levelorder(root);
cout<<endl;*/
/*node * root2=createmirror(root);
levelorder(root2);*/
postorder(root);
cout<<endl;
inorder(root);

}
