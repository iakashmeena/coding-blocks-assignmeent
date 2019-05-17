#include<iostream>
#include<math.h>
using namespace std;
int power(int n){
    int k=1;
    for(int i=1;i<=3;i++){
        k=k*n;
    }
    return k;
}
int main()
{
    int n;
    cin>>n;
    int k=n;
    int sum=0;
    while(k!=0){
        int p=k%10;
        sum=sum+(power(p));
        k=k/10;
    }
    if(sum==n){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
