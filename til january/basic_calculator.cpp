#include<iostream>
using namespace std;
int main()
{
    char ch[1];
    float n1,n2;
    int m1,m2;
    cin>>ch[1];
    while(ch[1]!='x'&&ch[1]!='X'){
    switch(ch[1]){
    case '+':
        cin>>n1;
        cin>>n2;
        cout<<n1+n2;
        break;

    case '-':
        cin>>n1;
        cin>>n2;
        cout<<n1-n2;
        break;

    case '*':
        cin>>n1;
        cin>>n2;
        cout<<n1*n2;
        break;
    case '/':
        cin>>n1;
        cin>>n2;
        if(n2!=0){
            cout<<n1/n2;
        }
        break;

    case'%':

        cin>>m1;
        cin>>m2;
        if(m2!=0){
            cout<<m1%m2;
        }
        break;

    default:
    cout<<"invalid operation";
    break;
    }
    cin>>ch[1];
}


return 0;
}
