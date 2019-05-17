#include <iostream>

using namespace std;

int main()
{






   /* int n;
    int x;
    int num=1;
    cout<<"enter the no. ";
    cin>>n;
    cout<<"enter the power ";
    cin>>x;


    for(int i=0;i<x;i++)
{
    num=num*n;
}
cout<<"\n result "<<num;

*/



/*int n;

cout<<"enter the three digit no. ";
cin>>n;

int a=n%10;
int b=(n-a)%100;
int c=n-(a+b);

int d=a*100+b+c/100;
cout<<endl<<d;

*/



    /*


    for (int i=1;i<=10;i++)
{

    int n=3*i+2;


    cout<<n<<"\t";



    if(n%4!=0 )
        {


        cout<<n;
    }
 cout<<endl;
}

*/





/*
char a;
cout<<"enter the character ";
cin>>a;
//int x=(int)a;




for(int i=0;i<26;i++)
{
    char p=65+i;
    char l=97+i;
   // cout<<p<<"\t"<<l<<endl;

    if ( a== p)
    {
        cout<<"upper case ";
        return 0;
    }

    else if(a == l)
        {
            cout<<"lower case";
          return 0;
        }





         else
            {
                      cout<<"wrong choice";
         return 0;
            }


}



/*
if((x>=65)&&(x<=91))
{
    cout<<"upper case ";
}
 else if((x>=97)&&(x<=123))
 {
     cout<<"lower case";
 }

 else
 {
     cout<<"wrong case";
 }
*/





/*
int basic, allow;
char a;

cout<<"enter the basic  :";
cin>>basic;
cout<<"enter the grade  :";
cin>>a;
if(a=='A')
{
    allow=1700;
}
else if(a=='B')
{
    allow=1500;
}
else if(a=='C')
{
allow=1300;
}

else
    {
    cout<<"\n\t\twrong choice";
return 0;

    }
float hra=0.2*basic;
float da=0.5*basic;
float pf=0.11*basic;

float t_sal=basic+hra+da+allow-pf;

cout<<"\ntotal sallary   : "<<t_sal;
*/



int n,p;
int sum=0;
int pro=1;
//bool product=1;
cout<<"enter the no. : ";
cin>>n;
cout<<"press '1' for product or '2' for sum ";
cin>>p;
 if (p==1 || p==2)
 {
     for(int i=1;i<=n;i++)
  {
      if(p==1)
      {
          pro=pro*i;
      }
      else
        {
        sum=sum+i;
        }
  }
 }
 else{

    cout<<"wrong choice";
    return 0;
 }

  if(p==1)
  {
      cout<<"\nproduct "<<pro;
  }
  else
    {
    cout<<"\nsum "<<sum;
    }
return 0;
}

