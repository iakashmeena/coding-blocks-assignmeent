#include<iostream>
using namespace std;
int main()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    for(int i=1;i<=(n1*n2);i++){
        if(i%n1==0&&i%n2==0){
             cout<<i;
            break;
        }
    }
}

