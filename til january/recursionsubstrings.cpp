#include<iostream>
using namespace std;
void printsub(char arr[],int index,char arr2[]){
    if(arr[index]==NULL){
        return;
    }
    int i;
    printsub(arr,index+1,arr2);
    for( i=index;arr[i]!=NULL;i++){
        arr2[i]=arr[i];

    }
    arr2[i]=NULL;
    cout<<arr2;
    cout<<endl;
    return;

}
int main()
{
    char arr[100];
    cin.getline(arr,100);
    char arr2[100];
    //cin.getline(arr2,100);
    printsub(arr,0,arr2);
}

