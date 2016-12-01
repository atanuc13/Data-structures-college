/* push,pop and display operation of stack in c*/

#include<stdio.h>
#define SIZE 50
void push(int);
void pop();
void display();
int stack[SIZE],top=-1;

int main()
{
    int a,b;
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
          scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("enter the number you want to insert:\n");
            scanf("%d",&b);
            push(b);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("wrong input\nplease enter a valid input");
        }
    }
}

//function to insert an element to the stack
void push(int x)
{
    if(top<SIZE-1)
    {
        top++;
        stack[top]=x;
    }
    else
        printf("stack is over flow\n");
}

//function to delete an element from the stack
void pop()
{
    int temp;
    if(top==-1)
        printf("sdtack is empty");
    else
    {
        temp=stack[top];
        top--;
        printf("the deleted item is %d",temp);
    }

}

//function to display the elements of the stack
void display()
{
    if(top!=-1)
    {
        int i;
        printf("the stack is:\n");
        for(i=top;i>=0;i--)
            printf("%d\t\t",stack[i]);
    }
    else
        printf("\nstack is underflow");
}
