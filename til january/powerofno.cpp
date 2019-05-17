#include<iostream>
using namespace std;
int main()
{
    int n;
    int m;
    int k=1;
    cin>>n;
    cin>>m;
    for(int i=1;i<=m;i++){
        k=k*n;
    }
    cout<<k;
}
