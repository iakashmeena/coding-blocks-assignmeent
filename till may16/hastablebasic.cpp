/*#include<iostream>
#include<string.h>
using namespace std;
class node{
public:
    int data;
    string key;
    node*next;
    node(string key,int data){
        this->key=key;
        this->data=data;
        next=NULL;
    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
};
class hastable{
    node**bucket;
    int cs;
    int ts;

    int hasfuction(string key){
        int l=key.length();
        int pow=1;
        int ans=0;
        for(int i=0;i<l;i++){

            ans+=key[l-i-1]*pow;
            pow=pow*37;   //k=37
            pow=pow%ts;
            ans=ans%ts;
        }
        return ans;
    }

    void rehash(){
        node** oldbucket=bucket;
        int oldts=ts;
        ts=2*ts;
        cs=0;
        bucket=new node*[ts];
        for(int i=0;i<ts;i++){
            bucket[i]=NULL;
        }
        for(int i=0;i<oldts;i++){
            node*temp=oldbucket[i];
            while(temp){
                insert(temp->key,temp->data);
                temp=temp->next;
            }
            delete oldbucket[i];
        }
        delete [] oldbucket;
    }
public:
    hastable(int tablesize){
        bucket=new node*[tablesize];
        for(int i=0;i<tablesize;i++){
            bucket[i]=NULL;
        }
        cs=0;
        ts=tablesize;
    }

    void insert(string key,int data){
        int h=hasfuction(key);
        node*temp=new node(key,data);
        temp->next=bucket[h];
        bucket[h]=temp;
        cs++;
        float f=cs/ts;
        if(f>0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0;i<ts;i++){
            node*temp=bucket[i];
            cout<<"bucket "<<i<<" ";
            while(temp){
                cout<<temp->key<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL";
            cout<<endl;
        }
    }
    node*search(string k){
        int h=hasfuction(k);
        node*temp=bucket[h];
        while(temp){
            if(temp->key==k){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }


};
int main()
{
    hastable h(7);
    h.insert("Mango",10);
    h.insert("Apple",100);
    h.insert("Banana",100);
    h.insert("chiku",100);
    h.insert("Guava",100);
    h.insert("pine",100);
    h.insert("orange",100);
    h.print();



}
*/
#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>m;
    m.insert(make_pair("app",20));
    m.insert(make_pair("ban",3));
    while(!m.empty){

    }
}
