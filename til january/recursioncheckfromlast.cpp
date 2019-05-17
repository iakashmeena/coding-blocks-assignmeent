#include<iostream>
using namespace std;
int checklast(int arr[],int n,int index,int m){
    if(index==n){
       return -1;
    }
    int last_index=checklast(arr,n,index+1,m);
    if(last_index!=-1){
        return last_index;
    }
    if(arr[index]==m){
        return index;
    }
    return -1;
}
int checkfirst(int arr[],int n,int index,int m){
    if(index==n){
        return -1;
    }
    int firstindex=checkfirst(arr,n,index+1,m);
    if(arr[index]==m){
        return index;
    }
    if(firstindex!=-1){
        return firstindex;
    }
    return -1;
}
bool check(int arr[],int n,int index,int m){
    if(index==n){
        return false;
    }
    bool chik=check(arr,n,index+1,m);
    if(arr[index]==m){
        return true;
    }
    if(chik==true){
        return chik;
    }
    return false;
}
int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    //cout<<checklast(arr,n,0,m);
    //cout<<checkfirst(arr,n,0,m);
    //cout<<check(arr,n,0,m);
}
