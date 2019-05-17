#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=2;
    int c1=n+1;
    for(int i=1;i<=n;i++){
        int k=i;


        for(int k=n;k>i;k--){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<k++<<" ";
        }
        int p=c;
        if(i>1){
            for(int j=1;j<i;j++){
                cout<<p--<<" ";
            }
        c=c+2;
        }


        cout<<endl;
    }
    for(int i=1;i<n;i++){
        for(int k=1;k<=i;k++){
            cout<<"  ";
        }
        int p=n-i;
        for(int j=1;j<=n-i;j++){
            cout<<p++<<" ";
        }
        int l=p-2;
        for(int j=1;j<n-i;j++){
            cout<<l--<<" ";
        }

        cout<<endl;
    }
}
