#include <iostream>

using namespace std;

int main()
{
int arr[10]={0,1,2,3,4,5,6,7,8,9};
int x, n=10;
cout<<"enter the no";
cin>>x;
int start=0;
int end=n;
while(start<end){
    int mid=(start+end)/2;
    if(arr[mid]==x){
        cout<<"found";
        return 0;
    }
    else if(x>mid){
        start=mid+1;
    }
    else {
        end=mid-1;
    }

}
 cout<<"not found";
    return 0;
}
