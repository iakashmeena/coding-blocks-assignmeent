#include<iostream>
using namespace std;
int main()
{
    int arr[1000];
    int i=0;
    int n;
    int m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    while(i<n){
        if(arr[i]==m){
            cout<<i;
            return 0;
        }
        ++i;
    }
    cout<<-1;
}
