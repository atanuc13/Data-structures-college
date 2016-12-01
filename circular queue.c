/* Program in c to perform insertion,deletion and display operation of circular queue */
#include<stdio.h>
#define SIZE 6

struct queue
{
    int f,r,list[SIZE];
}a;
void insertion(struct queue *,int);
void deletion( struct queue *);
void display( struct queue *);

int  main()
{
    a.f=0;
    a.r=0;
    int i,x;
    while(1)
    {
        printf("\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter the number you want to insert:\n");
            scanf("%d",&x);
            insertion(&a,x);
            break;
        case 2:
            deletion(&a);
            break;
        case 3:
            display(&a);
            break;
        case 4:
            exit (0);
        default:
            printf("wrong input\n");
        }
    }
    return 0;
}

//function to perform insertion operation of circular queue
void insertion(struct queue *a,int x)
{
  if((a->r+1)%SIZE==a->f)
        printf("insertion not possible as because queue is almost full\n");
  else
  {
      a->list[a->r]=x;
      a->r=(a->r+1)%SIZE;
  }
}

//function to perform deletion operation of circular queue
void deletion( struct queue *a)
{
    int t;
    if(a->f==a->r)
        printf("queue is underflow");
    else
    {
        t=a->list[a->f];
        printf("deleted item is %d\n",t);
        a->f=(a->f+1)%SIZE;
    }
}

//function to perform display operation of circular queue
void display(struct queue *a)
{
    if(a->r!=a->f)
    {
        printf("the elements of circular queue:\n");
        int i;
        for(i=a->f;i<a->r;i++)
            printf("%d\t",a->list[i]);
    }
    else
        printf("\nqueue is underflow");
}
