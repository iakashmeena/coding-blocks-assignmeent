#include<iostream>
using namespace std;
void bubblesort(int arr[],int i,int n){
    if(i==n){
        return;
    }

    if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
     if(i==n-1){
       return bubblesort(arr,0,n-1);
    }
    bubblesort(arr,i+1,n);
    return;
}

int main()
{
    int arr[100]={5,41,32,2,0};
    bubblesort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
