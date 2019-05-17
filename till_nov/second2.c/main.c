#include <stdio.h>
#include <stdlib.h>

typedef struct book
{
    int bokId;
    char bokNam[10];
    int bokPric;
}b;
int main()
{
    b b1;

    printf("enter book id");
    scanf("%d",&b1.bokId);
    printf("enter book name");
    gets(b1.bokNam);
    printf("enter book price");
    scanf("%d",&b1.bokPric);
    return 0;

}
