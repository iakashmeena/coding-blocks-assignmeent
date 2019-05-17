#include<iostream.h>
#include<process.h>
#include<conio.h>

int nVrtx,vArray[30],eMatrix[30][30];

void create()
{
 for(int i=0; i<nVrtx; i++)
    {
     cout<<"Enter data of Vertex "<<i+1<<" : ";
     cin>>vArray[i];
    }

    char ch;
    int v1,v2;

 do {
     cout<<"Do you want to add an Edge ? [Y/N]";
     cin>>ch;
      if(ch=='y' || ch=='Y')
	{ cout<<"Enter Vertex 1 : ";
	 cin>>v1;
	 cout<<"Enter Vertex 2 : ";
	 cin>>v2;
	 for(int i=0;i<nVrtx;i++)
	    {  if (vArray[i]==v1) {v1=i;break;}
	    }
	 for(int j=0;j<nVrtx;j++)
	    {  if (vArray[j]==v2) {v2=j;break;}
	    }
	 eMatrix[v1][v2]=1;
	 eMatrix[v2][v1]=1;

	}

 }while(ch=='y' || ch=='Y');

}

int visited[30];

void display(int node)
{
 visited[node]=1;
 cout<<vArray[node]<<"-";

 for(int i=0;i<nVrtx;i++)
   {if(eMatrix[node][i]==1 && visited[i]==0)
     {
      display(i);
     }
   }
}

void main()
{
 clrscr();

 cout<<"Enter the no. of vertex";
 cin>>nVrtx;

 for(int i=0;i<nVrtx;i++)
 { for(int j=0;j<nVrtx;j++)
   { eMatrix[i][j] = 0;
   }
 }

 create();

 char ch;
 int v;
 re:
 clrscr();
 cout<<"1.Check Degree\n2.Display";
 ch=getch();
 clrscr();
 switch(ch)
  {
   case '1': int degree=0;
	     cout<<"Enter the vertex : ";
	     cin>>v;
	     for(int i=0;i<nVrtx;i++)
	       {
		 if(vArray[i]==v)
		   {
		    for(int j=0;j<nVrtx;j++)
		      {
		       if(eMatrix[i][j]==1) degree++;
		      }
		    break;
		   }
	       }
	     cout<<"Degree : "<<degree;
	     getch();
	     break;

   case '2': for(i=0;i<nVrtx;i++)
	       visited[i]=0;

	     display(0);
	     getch();
	     break;
   case 'b':
   case 'B': exit(0);

   default : break;

  }
 goto re;
}
