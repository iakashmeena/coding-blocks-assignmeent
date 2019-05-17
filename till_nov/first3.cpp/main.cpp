#include <iostream>

using namespace std;

int main()
{
int a,b;
cout<<"enter a and b";
cin>>a>>b;

  for(int i=a-1;i<a;i--)
    {
        if(a%i==0&&b%i==0)
        {
             cout<<"\n"<<i;
            break;
                        }
    }


    return 0;
}
