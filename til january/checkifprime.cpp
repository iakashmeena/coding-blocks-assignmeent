#include<iostream>
using namespace std;
int main()
{
    int n;
    bool y=false;
    cin>>n;
    if(n<4){
        y=true;
    }
    else{
        for(int i=2;i<=(n/2);i++){
        if(n%i==0){
            cout<<"Not Prime";
            y=false;
            return 0;
        }
        else{
            y=true;
        }
    }

    }

    if(y==true){
        cout<<"Prime";
    }
    return 0;
}
