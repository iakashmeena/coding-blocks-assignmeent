#include<iostream>

using namespace std;
int main()
{
    int c=0;
    for(int i=2000;i<3000;i++)
    {
        if(i%4==0)
            c++;
    }
    cout<<c;
    return 0;
}
