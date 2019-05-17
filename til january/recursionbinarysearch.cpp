#include<iostream>
using namespace std;
bool binarysearch(int arr[],int n,int start,int end){
    if(start>end){
        cout<<"not found";
        return 0;
    }
    int mid=(start+end)/2;
    if(arr[mid]==n){
        return true;
    }
    else if(n<arr[mid]){
        return binarysearch(arr,n,start,mid-1);
    }
    else{
        return binarysearch(arr,n,mid+1,end);
    }
}
int main()
{
    int arr[100]={1,2,3,4,5,6,7,8,9,10};
    cout<<binarysearch(arr,18,0,9);

}
