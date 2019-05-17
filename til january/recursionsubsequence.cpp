#include<iostream>
//#include<string.h>
#include<math.h>
using namespace std;
int countsubsequences(char in[],int i,char out[],int j){
    if(in[i]=='\0'){
        out[j]='\0';
        return 1;
    }
    int k=countsubsequences(in,i+1,out,j);
    out[j]=in[i];
    int l=countsubsequences(in,i+1,out,j+1);
    return l+k;

}
void substring(char in[],int i,char out[],int j){
    if(in[i]=='\0'){
        out[j]='\0';
        /*if(out[0]=='\0'){
            cout<<'\0'<<" ";
            return;
        }*/
        cout<<out<<" ";
        return;
    }
    substring(in,i+1,out,j);
    out[j]=in[i];
    substring(in,i+1,out,j+1);

}
int power(int n){
    int k=1;
    for(int i=1;i<=n;i++){
        k=k*2;
    }
    return k;
}
int main()
{
    char in[100];
    cin>>in;
    char out[100];

    cout<<countsubsequences(in,0,out,0)<<endl;
    substring(in,0,out,0);

}
