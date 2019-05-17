#include<iostream>
using namespace std;
int main()
{
    char a;
    cin>>a;
    int k;
    k=a;
   if(k>=65&&k<=90){
    cout<<"UPPERCASE";
    return 0;
   }
   if(k>=97&&k<=122){
    cout<<"lowercase";
    return 0;
   }
   else{
    cout<<"invalid";
   }

}
