#include<iostream>
using namespace std;
int main()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    for(int i=1;i<=n1;i++){
        int p=3*(i)+2;
        if(p%n2!=0){
            cout<<p<<endl;
        }
        else{
            ++n1;
        }
    }
}
