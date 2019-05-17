#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;int c=2;
    for(int i=1;i<=n;i++){
        int k=i;


        for(int k=n;k>=i;k--){
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
}
