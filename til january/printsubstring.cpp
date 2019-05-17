#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[]={"abcd"};
    char arr2[100];
    for(int i=0;i<strlen(arr);i++){
        for(int j=i;j<strlen(arr);j++){
            int k;
            int p;
            for(k=i,p=0;k<=j;k++,p++){
               // for(p=0;p<=j;p++){
                    arr2[p]=arr[k];

            }
            arr2[p]=NULL;
            cout<<arr2;
            cout<<endl;
        }
    }
}
