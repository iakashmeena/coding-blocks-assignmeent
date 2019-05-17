#include<iostream>
using namespace std;
void arraysum(int arr1[],int n,int arr2[],int m,int arr3[],int x){
    int k=0;
    int n1=n;
    int m1=m;
    //cout<<"x  "<<x<<endl;
    while(n1>=0&&m1>=0){
        arr3[k]=arr1[k]+arr2[k];
        k++;
        n1--;
        m1--;
    }
   // cout<<"***********"<<"  "<<k<<endl<<n1<<"  "<<m1<<endl;
    if(m1!=-1){
        for(int i=k-1;i<x;i++){
            arr3[i]=arr2[i];
        }
    }
    else if(n1!=-1){
        for(int i=k-1;i<x;i++){
            arr3[i]=arr1[i];
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int arr1[100];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[100];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int x;
    if(m>n){
        x=m;
    }
    else if(n>m){
        x=n;
    }
    else{
        x=m;
    }
    int arr3[100];
    arraysum(arr1,n,arr2,m,arr3,x);
    for(int i=0;i<x;i++){
        cout<<arr3[i]<<", ";
    }
    cout<<"END";
}
