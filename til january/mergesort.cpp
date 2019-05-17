#include<iostream>
using namespace std;
void merge(int arr[],int start,int end){
    int mid=(start+end)/2;
    int temp[100];
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
         temp[k++]=arr[j++];
    }



    for(int p=0,l=start;l<=end;l++,p++){
        arr[l]=temp[p];
    }

}
void mergesort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,end);
}

int main()
{
    int arr[100]={5,41,32,2,0,6,10,3};
    mergesort(arr,0,7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}
