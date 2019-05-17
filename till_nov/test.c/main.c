#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b;
    int n;
    float sum,sub,pro,div,sqr,por;

    printf("\t\t\t\t\t\tCALCULATOR ");
    printf("\n\nenter the 1 no.");
    scanf("%f",&a);

    printf("press 1 for add or 2  for sub or 3 for mul. or 4 for divi. or 5 for sqrt or 6 for square  : ");
    scanf("%d",&n);

    if(n>0 && n<5)
    {

    printf("\nenter the  second no.");
    scanf("%f",&b);


        switch(n)
        {
     case 1:
        {
            sum=a+b;
        printf("\nresult is%f",sum);
        break;
    }

     case 2:
         {
                sub=a-b;
                printf("\nresult is %f",sub);
                break;
         }
     case 3:
         {
             pro=a*b;
             printf("\nresult is %f",pro);
             break;

         }
     case 4:
        {
            div=a/b;
             printf("\nresult is %f",div);
             break;
        }

     }}
     else if(n>4 && n<7)
     {
       switch (n)
         {
        case 5:
          {
            sqr=sqrt(a);
            printf("\nresult is %f",sqr);
            break;
        }
        case 6:
            {
            por=pow(a,2.000);
            printf("\nresult is %f",por);
            break;
            }

         }


     }


    else
    {
         printf("\nwrong choice");
    }
    return 0;

}
