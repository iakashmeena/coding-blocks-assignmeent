#include<iostream>
using namespace std;
int main()
{
    int y=INT_MAX;

    cout<<"enter the array"<<endl;
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    cout<<"your array"<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i];
    }
    for(int i=0;i<10;i++){
        if(arr[i]<y){
            y=arr[i];
        }
    }
    cout<<"lowest no"<<1110y;
}
