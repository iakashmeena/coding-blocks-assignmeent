#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int c=1;
        for(int j=1;j<=n-i+1;j++ ){
            cout<<c++<<" ";
        }
        if(i>1){
            for(int k=1;k<=i-1;k++){
            cout<<"* ";
        }
        }
        if(i>2){
            for(int k=1;k<=i-2;k++){
                cout<<"* ";
            }
        }

        cout<<endl;
    }
}
