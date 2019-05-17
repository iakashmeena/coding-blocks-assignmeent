#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[100];
    char arr2[100];
    cin.getline(arr,100);
    int i=0;
    int l=0;int p=strlen(arr);
    while(arr[i]!=NULL){
        int c=0;
        arr2[l]=arr[i];
        for(int j=i;arr[i]==arr[j];j++){
            if(arr[i]==arr[j]){
                c++;
            }
            else{
                break;
            }
        }
        i=i+c;
        l++;
    }
    arr2[l]=NULL;
    int j=0;
    while(arr2[j]!=NULL){
       arr[j]=arr2[j];
       j++;
    }
    arr[j]=NULL;
    cout<<arr;


}

