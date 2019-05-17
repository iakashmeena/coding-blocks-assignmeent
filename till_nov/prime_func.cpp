#include<iostream>
using namespace std;
bool binary(int arr[],int n,int num){
    int start=0;
    int end=n;
    int mid;


while(start<end){

    mid=(start+end)/2;
    if(arr[mid]==num){
        cout<<"found";
        return 1;
    }
    else if(num<arr[mid]){
        end=mid-1;
        }
    else if(num>arr[mid]){
        start=mid+1;
        }


}
cout<<"not found";
return 0;
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<binary(arr,10,10);

}


