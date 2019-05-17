#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p=n+1;
    for(int i=1;i<=n;i++){
        for(int j=n-i+1;j>=1;j--){
            cout<<"*";
        }
        if(i==1){
              for(int j=1;j<n;j++){
            cout<<"*";
            }
        }
       for(int k=1;k<i;k++){
            cout<<" ";
        }
        for(int k=1;k<i-1;k++){
            cout<<" ";
        }
        for(int j=n-1;j>=i-1&&i>1;j--){
            cout<<"*";
        }
        cout<<endl;
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<=i+1;j++){
                cout<<"*";
            }
            for(int k=1;k<n-i;k++){
                cout<<" ";
            }
            for(int k=1;k<n-i-1;k++){
                cout<<" ";
            }
            for(int j=1;j<=i+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }

        for(int i=1;i<(2*n);i++){
            cout<<"*";
        }
        cout<<endl;
    }

