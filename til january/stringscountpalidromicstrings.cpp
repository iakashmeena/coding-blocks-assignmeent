//LARGEST STRING LENGTH
/*#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    cin.get();
    char maxarray[100];
    int maxlength=0;
    while(n){
        char arr[100];
        cin.getline(arr,100);
        int j=0;
        while(arr[j]!=NULL){
            j++;
        }
        if(maxlength<j){
            maxlength =j;
            int k=0;
            while(arr[k]!=NULL){
                maxarray[k]=arr[k];
                k++;
            }
            maxarray[k]=NULL;
        }
        n--;
    }
    cout<<maxarray;
}*/

//ISPALINDROME
#include<iostream>
using namespace std;
int main()
{
    char arr[100];
    int c=0;
    int i=0;
    cin.getline(arr,100);
    int length =0;
    while(arr[i]!=NULL){
        length++;
        i++;
    }
    char arr2[100];
    //cout<<length<<endl;
    for(int i=0;i<=length;i++){
        for(int j=i;j<length;j++){
            int k;
            int l;
            for(k=i,l=0;k<=j;k++,l++){
                arr2[l]=arr[k];
            }
            arr2[l]=NULL;
            int length2=-1;
            for(int q=0;arr2[q]!=NULL;q++){
                length2++;
            }
            bool y=true;
            int start=0;
            int end=length2;
            while(start<end){
                if(arr2[start]==arr2[end]){
                    start++;
                    end--;
                }
                else{
                    y=false;
                    break;
                }
            }
            if(y==true){
                c++;
            }

        }

    }
    cout<<c;

}

