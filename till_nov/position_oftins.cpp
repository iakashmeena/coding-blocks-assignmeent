#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char t[10]={"fgh"};
    char s[20]={"fghabcfgh"};
    int n1=strlen(s)-1;
    int n2=strlen(t)-1;
    int j;
    int l=0;
    for(int i=n2;i>=0;i--){
             bool found=false;

        for(j=n1;j>=0 && found==false;j--){
                if(t[i]==s[j]){

                    found=true;
                }
        }
        l++;
        if(found!=true){
            cout<<"not found";
            return 0;
        }
        if(l==n1){
            cout<<"found"<<j;
            return 0;
        }
    }
}

