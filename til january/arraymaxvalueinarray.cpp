#include<iostream>
using namespace std;
int max(int arr[],int n){
    int max=-9999999;
    for(int i=0;i<n;i++){
        if(max<=arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max(arr,n);
}
