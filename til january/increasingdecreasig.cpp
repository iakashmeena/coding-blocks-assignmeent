#include<iostream>
using namespace std;
int main()
{
    int n;
    int i=0;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]<arr[1]){
        cout<<"false";
        return 0;
    }
    else{
        while(arr[i]>arr[i+1] && i<=n){
            ++i;
        }

        if(i>=n){
            cout<<"false";
            return 0;
        }
        while(arr[i]<arr[i+1] && i<=n){
            ++i;
        }
        if(i>=n){
            cout<<"true";
            return 0;
        }
        else{
            cout<<"false";
            return 0;
        }
    }
}
