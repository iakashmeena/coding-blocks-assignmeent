#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int c=1;
        for(int j=1;j<=i;j++){

            cout<<c++<<" ";
        }
        for(int k=1;k<=n-i;k++){
            cout<<"  ";
        }
        for(int s=1;s<=(n-i)-1;s++){
            cout<<"  ";
        }
        for(int a=i;a>=1;a--){
                if(a!=n){
                    cout<<a<<" ";
                }

        }
        cout<<endl;
    }

}
