#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[100];
    cin.getline(arr,100);
    int l=strlen(arr);
    //NOTREQUIRED
    /*char arr2[100];
    strcpy(arr2,arr);

    for(int i=0;i<=l;i++){
        for(int j=0;j<l-i-1;j++){
            if(arr2[j]>=arr2[j+1]){
                char temp;
                temp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=temp;
            }
        }
    }
    //cout<<arr2;*/
    char max;
    int maxfrequency=0;
    for(int i=0;i<=l;i++){
        char k=arr[i];
        int c=0;
        for(int j=0;j<=l;j++){
            if(arr[i]==arr[j]){
                c++;
            }
            if(c>maxfrequency){
                maxfrequency=c;
                max=k;
            }
        }

    }
    cout<<max;

}
