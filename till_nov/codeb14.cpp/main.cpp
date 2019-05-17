#include <iostream>

using namespace std;

int main()
{
  int n;
  cout<<"enter the no.of row";
  cin>>n;

  for(int i=n;i>=1;i--)
  {
      int p=0;
      int l=i-1;
     for(int j=1;j<=i;j++)
     {

         cout<<char(65+p);
         p++;
     }

     for(int k=1;k<=i;k++)
     {
          cout<<char(65+l);
         l--;

     }


     cout<<endl;
  }
  return 0;
}
