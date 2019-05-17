#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;
     //struct node*head='NULL';
       // struct node *p,*q;
}node;
void create()
{
     struct node*head='NULL';
        struct node *p,*q;
    p=(struct node*)malloc(5*(sizeof(node)));

    printf("enter data");
    scanf("%d",&p->data);
    p->next='NULL';
    if(head=='NULL')
    {
        head=p;
    }
    else
    {
            q->next=p;
    }
    q=p;

    }
    void display()
    {
         struct node*head='NULL';
        struct node *p,*q;

        q=head;
        while(q!='NULL')
        {
            printf("%d",q->data);
            q=p;
            q=q->next;
        }
    }
int main()
{

  int count=5;
  for(int i=0;i<5;i++)
    create();
    display();

}

