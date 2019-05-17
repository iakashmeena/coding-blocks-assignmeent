#include <iostream>

using namespace std;

int main()
{

    int n;

    cout<<"enter the no. ";
    cin>>n;
for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;;j++)
        {
            cout<<" ";
        }
          for(int p=0;p<=2i-1;i++)
           {
              cout<<"*";
                 }
}
               return 0;
}
