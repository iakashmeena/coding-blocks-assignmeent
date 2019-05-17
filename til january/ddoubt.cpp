#include<iostream>
#include<string.h>
using namespace std;
void printsub(char arr[100],int index,int n,char ans[100],int i){
    if(n==index){
        ans[i]=NULL;
        cout<<ans;
        cout<<endl;
        return;
    }
    ans[i]=arr[index];
    printsub(arr,index+1,n,ans,i+1);
    printsub(arr,index+1,n,ans,i);

}
/*void substring(char arr[100],int index,int  n,char ans[100],int k){
    if(index==n){
        return;
    }
    int p=0;
    for(int i=index;i<n;i++){
        ans[p]=arr[i];
        p++;
    }
    ans[p]=NULL;
    cout<<ans;
    substring(arr,index+1,n,ans,);
}*/
void splitarray(int arr[100],int i,int n,int arr1[50],int i1,int arr2[50],int i2){
    if(i==n){
        int sum1=0;
        for(int f=0;f<i1;f++){
            sum1+=arr1[f];
        }
        int sum2=0;
        for(int f=0;f<i2;f++){
            sum2+=arr2[f];
        }
        if(sum1==sum2){
            for(int f=0;f<i1;f++){
                cout<<arr1[f]<<" ";
            }
            cout<< " ";
            for(int f=0;f<i2;f++){
                cout<<arr2[f]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    arr1[i1]=arr[i];
    splitarray(arr,i+1,n,arr1,i1+1,arr2,i2);
    arr2[i2]=arr[i];
    splitarray(arr,i+1,n,arr1,i1,arr2,i2+1);
}

int main()
{
    /*char arr[100];
    char ans[100];
    cin.getline(arr,100);
    int n=strlen(arr);*/
    //printsub(arr,0,n,ans,0);
    //substring(arr,0,n,ans,0);
   /* int arr[100];
    int arr1[50];
    int arr2[50];
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    splitarray(arr,0,6,arr1,0,arr2,0);*/
    int n;
    cin>>n;
    int a[n];
    int b[n];
    a[0]=1;
    b[0]=1;
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
     }

}
