#include<iostream>
using namespace std;
int main()
{
    char arr[100];
    cin.getline(arr,100);
    int i=0;
    while(arr[i]!=NULL){
        int k=0;
        for(int j=i;arr[i]==arr[j];j++){
            k++;
        }
        cout<<arr[i];
        if(k>1){
            cout<<k;
        }
        i=i+k;
    }

}
