#include<iostream>
using namespace std;
void merge(int arr[],int start,int end){
    int mid=2;
    int start1=start;
    int start2=mid+1;

    int end1=mid;
    int end2=end;
    int arr2[10];
    int i=0;
    while(i<end){
        if(arr[start1]>arr[start2]){
            arr2[i]=start2;
            i++;
            start1++;
            }
            else if(arr[start1]<arr[start2]){
            arr2[i]=start1;
            i++;
            start2++;
            }



}     for(int j=0;j<i;j++){
                cout<<arr2[j]<<" ";
            }}

int main(){
int arr[10]={4,5,6,1,2,3};
merge(arr,0,6);



}
