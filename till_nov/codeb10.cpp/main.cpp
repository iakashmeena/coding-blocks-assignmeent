#include<iostream>
using namespace std;

int main()
{
    int n;
    int num=0;
    cout<<"enter the nn.";
    cin>>n;

    for(int i=0;i<32;i++)
    {
         if(n&1==1)
            {
                    num++;
                  }
        n>>1;

    }
    cout<<num;

return 0;

}
