#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=n;

    for(int i=1;i<=n;i++){
        for(int k=1;k<=i-1&&i>1;k++){
            cout<<"  ";
        }
        int k=c;
        for(int j=c;j>=0;j--){
            cout<<k--<<" ";
        }
        for(int j=1;j<=c;j++){
            cout<<j<<" ";
        }
         --c;
        cout<<endl;
    }
    for(int i=0;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            cout<<"  ";
        }
        for(int j=i;j>=0;j--){
            cout<<j<<" ";
        }
        if(i>0){
            for(int j=1;j<=i;j++){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
