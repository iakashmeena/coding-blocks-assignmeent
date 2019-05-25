/*
ARRAYLIST OF LEVELS ( BINARY TREE )
Given a Binary tree, write code to create a separate array list for each level.
You should return an arraylist of arraylist.


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format
where true suggest the node exists and false suggests it is NULL
*/
#include<bits/stdc++.h>
#include<vector>
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
node<T>* createbtree(node<T>*root,bool want_to_insert=1){
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
void all_node(node<T>*&root,map<int,list<T> > &m){
    if(root==NULL){
        return;
    }
    queue<node<T>*> q1;
    queue<node<T>*> q2;
    int i=0;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        if(!q1.empty()){

            while(!q1.empty()){
                node<T>*top=q1.front();
                m[i].push_back(top->data);
                q1.pop();
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
             m[i].push_back(top->data);
            q2.pop();
                if(top->left){
                    q1.push(top->left);
                }
                if(top->right){
                    q1.push(top->right);
                }
            }

        }
        i++;
    }
    return;
}
int main()
{
    map<int ,list<int> > m;
    node<int>*root=NULL;
    root=createbtree<int>(root);
    all_node<int>(root,m);
    cout<<"[";
    for(auto it=m.begin();it!=m.end();it){

        cout<<"[";
        for(auto it2=it->second.begin();it2!=it->second.end();it2){
            cout<<*it2;
            it2++;
            if(it2!=it->second.end()){
                cout<<", ";
            }
        }

    cout<<"]";
    it++;
    if(it!=m.end()){
        cout<<", ";
    }
    }
    cout<<"]";

}
