#include <iostream>

using namespace std;

int main()
{
    char arr1[100];
    int  asci[255]={0};
    int i=0;
    cin.getline(arr1,100);
    while(arr1[i]!='\0'){
            for(int j=0;j<255;j++){
                if(arr1[i]==j){
                   asci[j]++;
                }
            }
    i++;
    }

    for(int i=0;i<255;i++)
    {
       if(asci[i]!=0)
       {
                   cout<<(char)i<<asci[i];
       }

    }
    return 0;
}
