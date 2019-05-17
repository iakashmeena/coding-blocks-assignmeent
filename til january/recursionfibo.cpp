#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int r=fibo(n-1);
    int k=fibo(n-2);
    int c=r+k;
    return c;
}
int main()
{
    int n=5;
    for(int i=1;i<=n;i++){
        cout<<fibo(i)<<" ";
    }
}
