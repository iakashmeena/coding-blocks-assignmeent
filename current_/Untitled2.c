#include<iostream>
using namespace std;

int LinearSearch(int arr[],int n, int k){
    for (int i=0;i<n;i++){
        if (arr[i]==k) return i;
    }
    return -1;
}

void SelectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int SmallestIndex=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[SmallestIndex])
                SmallestIndex=j;
        }
        swap(arr[i],arr[SmallestIndex]);
    }
}

void BubbleSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]) swap (arr[j+1],arr[j]);
        }
    }

}

void BubbleSortOpt(int arr[],int n){
    for (int i=0;i<n-1;i++){
        bool isSorted=true;
        cout<<i<<endl;
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap (arr[j+1],arr[j]);
                isSorted=false;
            }
        }
        if (isSorted) break;
    }

}

void InsertionSort(int arr[],int n){
    for (int i=1;i<n;i++){
        int temp=arr[i];
        for (j=i-1;j>=0&&arr[j]>temp;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[10]={4,3,9,8,1,0,6,2,7,5};
    int n=10;
    InsertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
