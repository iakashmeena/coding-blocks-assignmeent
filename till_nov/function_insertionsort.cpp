#include<iostream>
using namespace std;
void insertion(int arr[],int n){
 for(int i=2;i<n;i++)
 {
  int val=arr[i];
  int j=i-1;
  while(j>=0 && arr[j]>val)
  {
      arr[j+1]=arr[j];
      j--;
  }

  arr[j+1]=val;
}
for(int i=0;i<n;i++){

 cout<<arr[i];
}
}

int main()
{
    int arr[8]={5,7,1,2,3,9,8,4};
    insertion(arr,8);

}
