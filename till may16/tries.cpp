#include<iostream>
#include<map>
using namespace std;
//#definr hasmap unordered_map<char,node*>
class node{
public:
    char data;
    map<char,node*>h;
    bool isterminal;
    node(char data){
        this->data=data;
        isterminal=false;
    }
};
class trie{
    node*root;
public:
    trie(){
        root=new node(NULL);
    }
    void add(char *word){
        node*temp=root;
        for(int i=0;word[i]!=NULL;i++){
            char ch=word[i];
            if (temp->h.count(ch)==0){
                node*child=new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else{
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;

    }
    bool search(char *word){
        if(root==NULL){
            return 0;
        }
        bool found=true;
        node*temp=root;
        for(int i=0;word[i]!=NULL;i++){
            char ch=word[i];
            if(temp->h.count(ch)==1){
                temp=temp->h[ch];
            }
            else{
                found=false;
                return 0;
            }
        }
        return temp->isterminal;
    }
};
int main()
{
    trie t;
    t.add("apple");
    t.add("ape");
    t.add("coding");
    t.add("pudding");
    t.add("cheesy fries");
    cout<<t.search("coding");
}
