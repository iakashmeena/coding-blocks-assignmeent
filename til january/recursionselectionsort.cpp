#include<iostream>
using namespace std;
void selectionsort(int arr[],int n,int index){
    if(index==n){
        return;
    }
    int min=999999;
    int minindex;
    for(int j=index;j<n;j++){
        if(min>=arr[j]){
            min=arr[j];
            minindex=j;
        }
    }
    int temp=arr[index];
    arr[index]=arr[minindex];
    arr[minindex]=temp;

    selectionsort(arr,n,index+1);
    return;
}
int main()
{

    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
