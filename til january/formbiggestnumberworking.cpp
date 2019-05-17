#include<iostream>
using namespace std;
int countdigit(int n){
    int p=0;
    while(n){
        n=n/10;
        p++;
    }
    return p;
}
int power(int n){
    int k=1;
    for(int i=0;i<n;i++){
        k=k*10;
    }
    return k;
}
int biggest(int n, int m){
    int c=countdigit(m);
    int k=n*power(c)+m;
    return k;
}
int main()
{
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int arr[1000];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                int p=biggest(arr[j],arr[j+1]);
                int k=biggest(arr[j+1],arr[j]);
                if( p < k ){
                    //cout<<"true"<<endl;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        --t;
    }

}
