#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==m){
            cout<<mid;
            return 0;
        }
        else if(m>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<-1;
}
