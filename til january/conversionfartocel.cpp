#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int p;
    cin>>p;
    for(int i=n;i<=m;i=i+p){
        int k=(i-32)*5/9;
        cout<<i<<" "<<k<<endl;
    }
}
