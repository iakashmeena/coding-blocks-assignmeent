#include<iostream>
using namespace std;
int find_7(int arr[],int n,int index){
    if(index==n){
            //cout<<"found";
        return -1;
    }
    if(arr[index]==7){
        find_7(arr,n,index+1);
        return index+1;
    }




}
int main()
{
    int arr[10]={1,7,8,6,7,3,4};
    cout<<find_7(arr,7,0);

}
