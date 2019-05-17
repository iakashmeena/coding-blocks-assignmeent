#include<iostream>
using namespace std;
void spair(int arr[2],int n,int x){
for(int i=0;i<n;i++){
    for(int j=0;j<n && j!=i;j++)
    if(x==arr[i]+arr[j]){
        cout<<arr[i]<<" "<<arr[j];
    }
    else{
        continue;
    }
}
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    spair(arr,10,8);
}
