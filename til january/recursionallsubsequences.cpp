#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void sortlexo(char out[100][100],int n){

   for(int j=0;j<n;j++){
    for(int i=0;i<n-j-1;i++){
       int l=strcmp(out[i],out[i+1]);
       if(l>0){
            char arr[100];
            strcpy(arr,out[i]);
            strcpy(out[i],out[i+1]);
            strcpy(out[i+1],arr);

       }
    }
   }

    for(int i=0;i<n;i++){
        cout<<out[i]<<endl;
    }
}
//to copy in 2d array
int length=0;
void copy(char out[100][100],char out1[100]){
    strcpy(out[length++],out1);
}
//finding subsequences
void subsequence(char in[100],int i,char out1[100],int j,char out[100][100],int l){
    if(in[i]=='\0'){
        out1[j]='\0';
        copy(out,out1);
        return;
    }
    out1[j]=in[i];
    subsequence(in,i+1,out1,j+1,out,l+1);
    subsequence(in,i+1,out1,j,out,l+1);
}
int main()
{
    int c;
    cin>>c;
    cin.get();
    while(c>0){
    char in[100];
    cin.getline(in,100);
    int n=strlen(in);
    n=pow(2,n);
    char out1[100];
    char out[100][100];
    subsequence(in,0,out1,0,out,0);
   sortlexo(out,n);
    --c;
    }


}
