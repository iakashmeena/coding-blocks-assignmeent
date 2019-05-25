/*
VERTICAL ORDER PRINT BINARY TREE
You will be given a Binary Tree. Your task is to print the binary tree in Vertical Fashion. The image below describes how we define a vertical traversal of a tree.


Input Format:
You will be given an Integer N denoting the number of levels in the corresponding tree. On the next line you will be given (2^N)-1 integers denoting the level order input for the tree. If at any level any node is absent then that will denoted by -1 and every integer other than -1 shows the presence of a node at that level.

Output Format:
Print all nodes of a given column in the same line.


*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct node{
    T data;
    node*left;
    node*right;

    node(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
template<typename T>
node<T>*createbtree(){
    node<T>*root=NULL;
    queue<node<T>*>q;
    T data;
    cin>>data;
    root=new node<T>(data);
    q.push(root);
    while(q.empty()==0){
        node<T>*it=q.front();
        q.pop();

        cin>>data;
        if(data!=-1){
            node<T>*left=new node<T>(data);
            it->left=left;
            q.push(left);
        }
        cin>>data;
        if(data!=-1){
            node<T>*right=new node<T>(data);
            it->right=right;
            q.push(right);
        }
    }
    return root;
}

template<typename T>
void push_in_map(node<T>*root,map<int,list<T> > &m,int l){
    if(root==NULL){
        return;
    }
     m[l].push_back(root->data);
    push_in_map(root->left,m,l-1);

    push_in_map(root->right,m,l+1);
    return;
}

int main()
{
    node<int>* root=NULL;
    int levels;
    cin>>levels;
    if(k<1){
        return 0;
    }
    root=createbtree<int>();
    map<int,list<int> > m;
    push_in_map<int>(root,m,levels);
    for(auto it:m){
        for(auto i:m[it.first]){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}
