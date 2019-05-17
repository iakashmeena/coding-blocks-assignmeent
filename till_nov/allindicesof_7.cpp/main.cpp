#include <iostream>

using namespace std;
/*
void all_indices(int arr[],int n,int index){
    if(index==n){
        return;
    }
    if(arr[index]==7){
        cout<<index<<endl;
    }
    all_indices(arr,5,index+1);
    return;

}

int main()
{
    int arr[10]={7,2,5,7,7};
    all_indices(arr,5,0);
    return 0;
}
*/


void all_indices(int arr[],int n,int index){
    if(index==n){
        return;
    }
    all_indices(arr,5,index+1);
    if(arr[index]==7){
        cout<<index<<endl;
        return;
    }
    else{
        return;
    }

}
int main()
{
    int arr[10]={7,2,5,7,7};
    all_indices(arr,5,0);
    return 0;
}
