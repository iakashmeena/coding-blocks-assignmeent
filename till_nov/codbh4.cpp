#include<iostream>
using namespace std;

int main()
{
//intersection of two arrays
/*
int a1[5]={1,2,3,4,5};
int a2[5]={1,6,7,8,9};
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        if(a1[i]==a2[j])
            cout<<a1[i]<<" "<<a2[j];
    }
}
*/
    //bubble sort
    /*
    int arr[5]={5,4,3,2,1};
    int n=5;
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<n-i-1;j++)
        {
            int temp;
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    */

    //Selection sort
    /*

    int arr[5]={4,5,3,2,1};
    int n=5;
    int min=INT_MAX;
    int x,min_index,j;
    for(int i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]<min)
            {
             min=arr[j];
             min_index =j;
            }

        }

        x=arr[i];
        arr[i]=min;
        arr[min_index]=x;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

*/


//insertion sort

/*

int arr[5]={4,5,3,2,1};
int n=5;
for(int i=1;i<5;i++)
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

for(int i=0;i<n;i++)

{
    cout<<arr[i];
}

*/




//reversinng the array
/*
int arr[5]={5,4,3,2,1};
int i=0;
int j=4;
while(j>i)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
}
for(int k=0;k<5;k++)
{
    cout<<arr[k];
}
*/


//sum of triplets

int n=9;
int a[n]={1,2,3,4,5,6,7,8,9};
int x;
int k;
cout<<"enter the no .  ";
cin>>x;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {

        if(j!=i)
         {
             for(int k=0;k<n;k++)
            {
               if((k!=i) && (k!=j))
              {
                  if(x==a[i]+a[j]+a[k])
                  {
                     cout<<a[i]<<a[j]<<a[k]<<endl;
                   }
                       else
                  {
                    continue;
                 }
              }

             }
        }
    }
}






//Given 2N+1 numbers out of which N are duplicate find the non-duplicate number. {doubt}

/*
int arr[11]={1,2,3,4,5,11,5,4,3,2,1};
int n=11;
int i;

for( i=0;i<n;i++)
{  bool found=true;
    for(int j=0;j<n;j++)
    {
        if(arr[i] == arr[j] && j!=i)
        {
         found=false;
        }
         else
        {
            continue;
        }

    }
    if(found==true)
        {
            cout<<arr[i];
            break;
        }
}
*/

//sum of two
/*
int a1[5]={1,2,3,4,5};
int a2[5]={6,7,8,9,0};
int sum[5];
for(int i=0;i<5;i++)
{
  sum[i]=a1[i]+a2[i];
}
for(int i=0;i<5;i++)
{
    cout<<sum[i]<<" ";
}

*/



//sorting array with 0 and 1 pass
/*
int arr[5]={0,1,0,1,0};
int  n=5;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
        int temp;
        if(arr[j]>arr[j+1])
        {

        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }
}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}

*/
return 0;
}
