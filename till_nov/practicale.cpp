#include<iostream>
using namespace std;
//exmaple of enumerator
enum weekdays{
sun,mon,sat
};


void make2d(int arr[3][3],int n,int m){
    for(int l=0;l<n;l++){
        for(int k=0;k<m;k++){
            cin>>arr[l][k];
        }
    }
}
void display(int arr[3][3],int n,int m){
    for(int l=0;l<n;l++){
        for(int k=0;k<m;k++){
            cout<<arr[l][k]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
   /* int arr[3][3];
    int arr2[3][3];
    make2d(arr,3,3);

    display(arr,3,3);
    make2d(arr2,3,3);
    display(arr2,3,3);

     */
     /*
     char str[100];
     char *ptr;
     cout<<"enter string";
     cin.getline(str,100);
     ptr=str;
     while(*ptr!='\0'){
        cout<<*ptr;
        ptr++;
     }*/
     enum weekdays wd=sat;

     cout<<wd;
}
