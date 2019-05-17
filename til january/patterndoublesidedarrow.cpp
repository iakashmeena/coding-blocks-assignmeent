#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p=n/2+1;
    int c=p-1;
    for(int i=1;i<=p;i++){
        for(int k=n/2;k>=i;k--){
            cout<<"    ";
        }
        for(int j=i;j>=1;j--){
            cout<<j<<" ";
        }
        if(i>1){
            for(int k=1;k<i;k++){
                cout<<"  ";
            }
        }
        if(i>2){
            for(int k=1;k<i-1;k++){
                cout<<"  ";
            }
        }
        if(i>1){
            for(int j=1;j<=i;j++){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=1;i<p;i++){
        for(int k=1;k<=i;k++){
            cout<<"    ";
        }
        for(int j=c;j>=1;j--){
            cout<<j<<" ";
        }
        for(int k=c;k>1;k--){
            cout<<"  ";
        }
      // c--;
        if(i!=n/2){
            for(int k=c;k>2;k--){
                cout<<"  ";
            }

        }
        c--;
        if(i!=n/2){
            for(int j=1;j<=p-i;j++){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
