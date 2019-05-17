#include<iostream>
using namespace std;
int sqt(int x){
    if(x==1){
        return 1;
    }
    int i;
    for(i=1;i*i<=x;i++);
    return i-1;
}
int main()
{
    int n;
    cin>>n;

    cout<<sqt(n);
}
