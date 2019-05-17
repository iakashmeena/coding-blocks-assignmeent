#include <iostream>
#include<math.h>

using namespace std;

int main()
{
  int num;
  int c=0;
  int i=1;
  float p=1;




  cout<<"enter the number ";
  cin>>num;


  while(num)
  {
      c++;
      num/=10;
  }
  cout<<c<<endl;




return 0;
}
