#include<iostream>
using namespace std;
void bubble(int arr[],int n,int index){
    if(index==n-1)
    {
        bubble(arr,n-1,0);
     return;
    }

       if(arr[index]>arr[index+1]){
        int temp=arr[index];
        arr[index]=arr[index+1];
        arr[index+1]=temp;



   }
   bubble(arr,n,index+1);
   return;


}
int main()
{
    int arr[10]={5,4,3,2,1};
    bubble(arr,5,1);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
