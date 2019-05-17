#include <iostream>

using namespace std;

int main()
{
int n;
cout<<"enter the no. of lines ";
cin>>n;
cout<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    for(int j=1;j<=n-i;j++){
        cout<<"*";
    }
    for(int j=0;j<n-i-1;j++){
        cout<<"*";
    }
    cout<<endl;
}
return 0;
}
