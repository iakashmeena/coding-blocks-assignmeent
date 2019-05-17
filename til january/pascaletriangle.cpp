#include<iostream>
using namespace std;
int fact(int n){
    int a=1;
    for(int i=1;i<=n;i++){
        a=a*i;
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=0;j<=i;j++){
            int k=fact(i);
            int l=fact(j);
            int y=fact(i-j);
            cout<<k/(l*y)<<" ";
        }
        cout<<endl;
    }
}
