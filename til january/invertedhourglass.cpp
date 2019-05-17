#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=n;
    for(int i=1;i<=n;i++){
        int k=n,k2=c;
        for(int j=1;j<=i;j++){
            cout<<k--<<" ";
        }
        for(int k=n;k>=i;k--){
            cout<<"  ";
        }
        for(int k=n;k>i;k--){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<k2++<<" ";
        }
        --c;

        cout<<endl;
    }
    for(int i=n;i>=0;i--){
        cout<<i<<" ";
    }
    for(int j=1;j<=n;j++){
        cout<<j<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<j<<" ";
        }
        for(int k=1;k<=i;k++){
            cout<<"  ";
        }
        for(int k=1;k<i;k++){
            cout<<"  ";
        }
        int k=i;
        for(int j=1;j<=n-i+1;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }
}
