#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int arr[1000];
        int i=0;
        int a;
        while(i<n){
            cin>>a;
            if(a==0||a==1){
                arr[i]=a;
                i++;
            }
        }
        int max=-999999;
        int largestindex;
        int smallestindex;
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                int count0=0;
                int count1=0;
                for(int p=j;p<=k;p++){
                    if(arr[p]==0){
                        count0++;
                    }
                    if(arr[p]==1){
                        count1++;
                    }
                }
                int sum=0;
                int p;
                if(count0==count1){
                    for(p=j;p<=k;p++){
                        sum+=arr[p];

                    }
                }
                if(sum>max){
                    max=sum;
                    largestindex=p-1;
                    smallestindex=j;

                }


            }
        }
        if(max>0){
            cout<<smallestindex<<" "<<largestindex<<endl;
        }
        else{
            cout<<"None"<<endl;
        }
        --t;
    }
}
