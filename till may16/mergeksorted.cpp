#include<iostream>
#include<vector>
#include<queue>
//#include<bits/std>
using namespace std;

void mergeksort(vector<int> v,int arr[100],int arr1[100],int arr2[100]){
    priority_queue<int,vector<int>,greater<int> >pq; //min heap
    int i=1;
    int j=1;
    int k=1;
    arr[5]=INT_MAX;
    arr1[4]=INT_MAX;
    arr2[7]=INT_MAX;
    pq.push(arr[0]);
    pq.push(arr1[0]);
    pq.push(arr2[0]);
    cout<<endl;
    while(k<7){
        int a=pq.top();
        v.push_back(a);
        pq.pop();
        if(arr[i]<arr1[j] && arr[i]<arr2[k]){
            pq.push(arr[i]);
            i++;
        }
        else if(arr1[j]<arr[i] && arr1[j]<arr2[k]){
            pq.push(arr1[j]);
            j++;
        }
        else {
            pq.push(arr2[k]);
            k++;
        }
    }

    v.push_back(pq.top());
    pq.pop();
    v.push_back(pq.top());
    pq.pop();
    v.push_back(pq.top());
    pq.pop();

}

int main()
{
    int p=0;
    vector<int>v;
    int arr[]={1,2,3,4,5};
    int arr1[]={6,7,8,9};
    int arr2[]={10,11,12,13,14,15,16};
    //mergeksort(v,arr,arr1,arr2);

    priority_queue<int,vector<int>,greater<int> >pq; //min heap
    int i=1;
    int j=1;
    int k=1;
   /* arr[5]=INT_MAX;
    arr1[4]=INT_MAX;
    arr2[8]=INT_MAX;*/
    pq.push(arr[0]);
    pq.push(arr1[0]);
    pq.push(arr2[0]);
    cout<<endl;
    while(k<7){
        int a=pq.top();
        v.push_back(a);
        pq.pop();
        if(arr[i]<arr1[j] && arr[i]<arr2[k]){
            pq.push(arr[i]);
            i++;
        }
        else if(arr1[j]<arr[i] && arr1[j]<arr2[k]){
            pq.push(arr1[j]);
            j++;
        }
        else {
            pq.push(arr2[k]);
            k++;
        }
    }

    v.push_back(pq.top());
    pq.pop();
    v.push_back(pq.top());
    pq.pop();
    v.push_back(pq.top());
    pq.pop();

    while(p<v.size()){
        cout<<v[p]<<" ";
        p++;
    }

}
