#include <iostream>

using namespace std;

int main()
{
    /*int n,l;
    cout<<"enter the no. of row";
    cin>>n;
int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i)
        {
            cout<<" ";

        j++;
        }
        int p=1;
        while(p<=2*i-1)
        {
            cout<<"*";
            p++;
        }
        cout<<endl;

        i++;
    }*/



    int n;
    cout<<"enter the no of row ";
    cin>>n;
     for(int i=2;i<n;i++)
     {
         if(n%i==0)
         {
             cout<<"not prime";

return 0;
         }

     }
cout<<"prime";
}
