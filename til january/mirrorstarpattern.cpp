#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=10){
            if(n%2==0){
        return 0;
    }
    else{
            int p=(n/2)+1;
    for(int i=1;i<=p;i++){
        for(int k=(p-i);k>0;k--){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int l=1;l<i;l++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=1;i<=(n/2);i++){
        for(int k=1;k<=i;k++){
            cout<<"  ";
        }
        for(int j=1;j<=((n/2)-i+1);j++){
            cout<<"* ";
        }
        for(int l=i;l<=(n/2)-1;l++){
            cout<<"* ";
        }
        cout<<endl;
    }
    }



    }
    return 0;

}
