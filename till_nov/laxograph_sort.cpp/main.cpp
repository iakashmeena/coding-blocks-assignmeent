#include <iostream>

using namespace std;

int main()
{
   char arr[100][100];
   int m;

   cin>>m;
   cin.get();
   for(int i=0;i<m;i++)
   {
       cin.getline(arr[i],100);
   }
   for(int i=0;i<m;i++)
   {
      for(int j=0;j<m-1;j++)

      {
          int k=0;
          while(arr[j][k]==arr[j+1][k] && arr[j][k]!='\0')
          {
              k++;

          }
          if(arr[j][k]>arr[j+1][k])
          {
              char temp[100][100];
              temp[100][100]=arr[j][k];
              arr[j][k]=arr[j+1][k];
              arr[j+1][k]=temp[100][100];
          }
      }

   }

       for(int i=0;i<m;i++)
       {
           //for(int j=0;j<n;j++)
            cout<<arr[i]<<endl;;
       }




    return 0;
}
