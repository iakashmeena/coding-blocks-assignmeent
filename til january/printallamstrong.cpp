#include<iostream>
using namespace std;
int power(int n){
    int k=1;
    for(int i=1;i<=3;i++){
        k=k*n;
    }
    return k;
}
bool isamstrong(int n){
    int k=n;
    int sum=0;
    while(k!=0){
        int p=k%10;
        sum=sum+(power(p));
        k=k/10;
    }
    if(sum==n){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    for(int i=n1+1;i<n2;i++){
        if(isamstrong(i)==1){
            cout<<i<<endl;
        }
    }

}
