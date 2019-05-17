#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2!=0){
        int p=n;
        while(p>0){
            cout<<p;
            p=p-2;
            cout<<endl;
        }
        p=2;
        while(p<=n){
            cout<<p;
            cout<<endl;
            p=p+2;
        }
    }
    else{
        int p=n-1;
        while(p>0){
            cout<<p;
            p=p-2;
            cout<<endl;
        }
        p=2;
        while(p<=n){
            cout<<p;
            cout<<endl;
            p=p+2;
        }
    }
}
