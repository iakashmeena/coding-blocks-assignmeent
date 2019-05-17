#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[100];
    cin.getline(arr,100);
    int i=0;
    while(arr[i]!=NULL){
        int p =arr[i];
        if(p>=65&&p<=90){
            arr[i]=tolower(arr[i]);
        }
        if(p>=97&&p<=122){
            arr[i]=toupper(arr[i]);
        }
        i++;
    }
    cout<<arr;
}
