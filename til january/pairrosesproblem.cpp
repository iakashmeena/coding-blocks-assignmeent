#include<iostream>
using namespace std;
void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int arr[100];
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,n);
        int m;
        cin>>m;
        int y=999999;
        int i1;
        int j1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(arr[i]<=arr[j]){
                        if (m==arr[i]+arr[j]) {
                         if (y>=arr[j]-arr[i]) {
                              y=arr[j]-arr[i];
                             i1=i;
                             j1=j;
                         }

                        }
                    }
                }
            }
        }
        cout<<"Deepak should buy roses whose prices are "<<arr[i1]<<" and "<<arr[j1]<<".";
        cout<<endl;
        --t;
    }


}
