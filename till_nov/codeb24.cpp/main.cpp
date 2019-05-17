#include <iostream>

using namespace std;

int main()
{
    char a;
    a=cin.get();

    int wl=0;
    int c=0;
    while(a!='$')
    {

        if(a=='\n'||a==' '|| a=='\t')
        {
            if(wl>0)
            {
                c++;
            }
            wl=0;
        }

        else

            {
            wl++;
        }
        a=cin.get();
    }
    if(wl>0)
    {
        cout<<++c;

    }
    else
        {

            cout<<c;
        }

    return 0;
}
