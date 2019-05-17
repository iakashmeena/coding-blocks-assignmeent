#include<iostream>
using namespace std;
int  log(int n,int m){
    int c=0;
    while(n){
        n=n/m;
        c++;
        }
    return c-1;
}
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    cout<<log(n,m);

}
