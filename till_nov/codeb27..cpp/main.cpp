#include <iostream>

using namespace std;

int main()
{
  int arr[7]={9,7,2,1,6,99,2};
  int n=7;

  for(int i=1;i<n;i++)
  {
      for(int j=0;j<i;j++)
      {
          if(arr[i]<arr[j])
          {
              int temp;
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;

          }

      }
  }

  for(int k=0;k<n;k++)
  {
      cout<<arr[k]<<" ";
  }
    return 0;
}
