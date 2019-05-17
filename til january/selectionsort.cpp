#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int y=9999999;
        int minindex;
        for(int j=i;j<n;j++){
            if(arr[j]<y){
                y=arr[j];
                minindex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}
