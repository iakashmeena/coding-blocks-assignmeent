#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>0){
       cout<<1;
    cout<<endl;
    for(int i=2;i<=n;i++){
        int p=i-1;
        for(int  j=1;j<=p+1;j++){
            if(j==1||j==p+1){
                cout<<1;
            }
            else{
                if(i%2==0&&i>2){
                     cout<<0;
                }
                else{
                    cout<<1;
                }

            }
        }
        cout<<endl;
    }
    }
    else{
        return 0;
    }


}

