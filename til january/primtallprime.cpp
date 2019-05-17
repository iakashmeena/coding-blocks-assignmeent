#include<iostream>
using namespace std;
void isprime(int  n){
    bool y=true;
    if(n<4){
        cout<<n<<endl;
        return ;
    }
    else{
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
            y=false;
            return ;
            }
        }

    }
    if(y==true){
        cout<<n<<endl;
        return;
    }
}
int main()
{
    int n;
    cin>>n;
    if(n<4){
        for(int i=2;i<=n;i++){
            cout<<i<<endl;
        }
    }
    else{
        for(int i=2;i<=n;i++){
                isprime(i);

        }
    }
}
