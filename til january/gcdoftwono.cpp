#include<iostream>
using namespace std;
int hcf(int n1,int n2){
    int k;
    int i;
    if(n1>n2){
        k=n2;
    }
    else if(n1<n2){
        k=n1;
    }
    else{
        k=n1;
    }
    for( i=k;i>=1;i--){
        if((n1%i==0 )&& (n2%i==0)){
           return i;
        }
    }

}
int main()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    cout<<hcf(n1,n2);

}
