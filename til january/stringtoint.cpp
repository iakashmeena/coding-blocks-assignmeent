#include<iostream>
#include<string.h>
using namespace std;
int strtointeger(char arr[]){
    if(arr[0]==NULL){
        return 0;
    }
    int n=strlen(arr);
    int x=arr[n-1]-48;
    arr[n-1]='\0';
    int l=strtointeger(arr);
    return l*10+x;
}
int main()
{
    char arr[100];
    cin.getline(arr,100);
    cout<<strtointeger(arr);

}
