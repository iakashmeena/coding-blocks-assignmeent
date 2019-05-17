#include<iostream>
using namespace std;
int nthtriangle(int n){
    if(n==1){
        return 1;
    }
    int k=nthtriangle(n-1);
    return k+n;
}
int main()
{
    int n;
    cin>>n;
    cout<<nthtriangle(n);

}
