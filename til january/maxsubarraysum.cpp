#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t){
        int arr[10000];
        int n;
        cin>>n;
        int max=-9999999;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum=sum+arr[k];
                }
                if(sum>=max){
                    max=sum;
                }
            }
        }
        cout<<max;
        --t;
    }


}
