#include<iostream>
using namespace std;
///quick sort
int pertiotion(int *arr,int s,int e){
    int i=s-1;
    int j=s;
    while(j<e){
        if(arr[j]<=arr[e]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}
void quick_sort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int p=pertiotion(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p,e);
    return;
}
int main()
{///insertion sort
    /*
    int arr[]={5,3,6,4,1,2,0};
    int x;
    for(int i=0;i<7;i++){
        x=arr[i];
        int j=i-1;
        for(j;j>=0&&arr[j];j--){
            if(arr[j]>x){
                arr[j+1]=arr[j];
            }
        }
        arr[j+1]=x;
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }*/
    int arr[]={5,3,6,4,1,2,0};

    quick_sort(arr,0,6);

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}
