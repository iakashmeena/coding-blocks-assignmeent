#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int r;
    int c=0;
    while(n){
        r=n%10;
        if(r==m){
            c++;
        }
        n=n/10;
    }
    cout<<c;
}
