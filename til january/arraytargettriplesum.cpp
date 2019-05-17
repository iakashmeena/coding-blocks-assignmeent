#include<iostream>
using namespace std;
void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void turgetsum(int arr[],int n,int n1){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==n1){
                    cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k];
                }
            }
        }
    }
}
int main()
{
    int arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    int target;
    cin>>target;
    turgetsum(arr,n,target);
    return 0;
}
