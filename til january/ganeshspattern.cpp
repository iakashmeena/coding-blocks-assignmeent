#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n/2;i++){
        cout<<"*";
        for(int k=1;k<n/2;k++){
            cout<<" ";
        }
        cout<<"*";
        if(i==1){
            for(int j=1;j<=n/2;j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=1;i<=n/2;i++){
        for(int k=1;k<=n/2&&i!=n/2;k++){
            cout<<" ";
        }
        if(i!=n/2){
            cout<<"*";
        }
        else{
            for(int j=1;j<=n/2+1;j++){
                cout<<"*";
            }
        }
         for(int k=1;k<n/2;k++){
            cout<<" ";
        }
        cout<<"*";


        cout<<endl;
    }
}
