#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p=(n/2)+1;
    for(int i=1;i<=p;i++){
        for(int j=p;j>=i;j--){
            cout<<"* ";
        }
        for(int k=1;(k<i)&&(i>1);k++){
            cout<<"  ";
        }
        for(int s=2;s<i&&i>1;s++){
            cout<<"  ";
        }
        if(i==1){
            for(int j=1;j<=n;j++){
                cout<<"* ";
            }
        }
        else{
            for(int j=n;j>=i-1;j--){
                cout<<"* ";
            }
        }

        cout<<endl;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=i+1;j++){
            cout<<"* ";
        }
        for(int k=n-1;k>=i;k--){
            if(i!=n){
                cout<<"  ";
            }
        }
        if(i!=n/2){
             for(int s=n/2-2;s>=i;s--){
        cout<<"  ";
       }
        }

       if(i==n-1){
         for(int l=1;l<=n;l++){
            cout<<"* ";
        }
        }

       else{
       for(int l=1;l<=i+1;l++){
            cout<<"* ";
       }

        cout<<endl;
    }
}}
