#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int y=0;
    int r;
    while(n){
        r=n%10;
        y=y*10+r;
        n=n/10;
    }
    cout<<y;
}
