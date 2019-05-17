#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[100];
    cin.getline(arr,100);
    for(int i=0;arr[i+1]!=NULL;i++){
        int k;
        k=arr[i+1]-arr[i];
        cout<<arr[i]<<k;
    }
    int l=strlen(arr);
    cout<<arr[l-1];
}
