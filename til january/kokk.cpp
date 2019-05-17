#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[10000];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            cin.get();
        }

        int max=0;
        int index;
        for(int i=0;i<n;i++){
            if(max<arr[i]){
                max=arr[i];
                index=i;
            }
        }
        cout<<index+1<<" "<<max<<endl;
        --t;
    }
}
