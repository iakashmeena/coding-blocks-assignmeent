#include <iostream>

using namespace std;

int main()
{
int n;
cout<<"enter n";
cin>>n;
for(int i=0;i<n;i++)
{
    for(int j=0;j<=i;j++)
       {
           cout<<"*";
       }
cout<<"\t";
           for(int k=n-1-i;k>=0;k--)

       {
           cout<<"*";
       }
cout<<"\t";
       for(int p=n-1-i;p>=0;p--)

       {
           cout<<"*";
       }
cout<<"\t";
       for(int l=0;l<=i;l++)
       {
           cout<<"*";
       }
cout<<endl;
}
return 0;
}
