#include<iostream>
using namespace std;
void substring(char in[],int i,char out[],int j){
    if(in[i]==NULL){
        out[j]=NULL;
        cout<<out<<",";
        return;
    }
    out[j]=in[i];
    substring(in,i+1,out,j+1);
    substring(in,i+1,out,j);
}
int main()
{
    char in[100];
    cin.getline(in,100);
    char out[100];
    substring(in,0,out,0);
}
