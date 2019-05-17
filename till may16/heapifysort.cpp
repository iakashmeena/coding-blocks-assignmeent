#include<iostream>
using namespace std;
void heapify(int arr[100],int i,int n){
    int minindex=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n&&arr[left]<arr[minindex]){
        minindex=left;
    }
    if(right<n&&arr[right]<arr[minindex]){
        minindex=right;
    }
    if(minindex!=i){
        swap(arr[i],arr[minindex]);
        heapify(arr,minindex,n);
    }
}
void heapsort(int arr[100],int n){
    for(int i=n-1;i>0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[1]);
        heapify(arr,1,i);

    }
}
int main()
{
    int arr[100]={-1,9,5,4,7,6,1,2,3,8};
    heapsort(arr,9);
    for(int i=1;i<9;i++){
        cout<<arr[i]<<" ";
    }
}
