#include<iostream>
using namespace std;
void insertionsort(int arr[],int n,int index){
    if(index==n){
        return;
    }
        int key=arr[index];
        int j=index-1;

        while(j>=0&&key<arr[j]){
              arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    insertionsort(arr,n,index+1);
}
int main()
{

    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n,1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
