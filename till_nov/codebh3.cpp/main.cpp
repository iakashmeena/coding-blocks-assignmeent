#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    /*
    int n;
    long int fact=1;
    int count=0;
    cout<<"enter the no. ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout<<fact;
    while(fact/10)
    {
        if(fact%10==0)
        {
            fact=fact/10;
            count++;
        }
        else
        {
            break;
        }
    }

    cout<<endl<<count;

    */

    /*
    int p=0;
    for(int i=2000;i<3000;i++)
    {
        if(i%4==0)
        {

            cout<<endl<<i;
            p++;
        }

    }
    cout<<endl<<"\n\n\n"<<p;

    */

    /*
    int n;
    cout<<"enter the no. ";
    cin>>n;
    if(n>1)
    {
        if((n-2)%4==0)
        {
            cout<<"in ap";


        }
        else
        {
            cout<<"not in ap";
        }
    }
    else
    {
        cout<<"not in ap";
    }

    */

    /*

    int a,b,c;
    float p;
    float x1,x2;
    cout<<"enter a,b and c ";
    cin>>a>>b>>c;
    int l=4*(a*c);
     p=pow(b,2)-(l);
    if(p>=0)
    {
        x1=((-1*b)+sqrt(p))/2*a;
        x2=((b)+sqrt(p))/2*a;
    }
    if(p<0)
    {
        cout<<"imaginary roots";
    }


    */


    /*
    char a;
    float avg;
    cout<<"enter name ";

    cin>>a;
    a=cin.get();
    while(a!='\n')
    {
        a=cin.get();
    }
    int n1,n2,n3;
    cout<<"enter the no.  ";
    cin>>n1>>n2>>n3;

    if(n1>n2 && n3>n2)
    {
        avg=(n1+n3)/2;
    }
    if(n2>n1 && n3>n1)
    {
        avg=(n2+n3)/2;
    }
    if(n2>n3 && n1>n3)
    {
        avg=(n2+n1)/2;
    }
    cout<<endl<<avg;

    */



    return 0;
}
