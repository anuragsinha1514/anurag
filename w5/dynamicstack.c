#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int key;
} ele;
ele *stack;
int capacity=1;
int top=-1;
void push()
{
    int x,n;
    if(top>=capacity-1)
    {
        printf("Stack full...adding space\n");
    stack=(ele *)realloc(stack,2*capacity*sizeof(*stack));
    capacity*=2;
    }
    printf("Enter the element to be pushed\n");
    scanf("%d",&n);
    stack[++top].key=n;
}
void pop()
{
    if(top<0)
        printf("Stack Empty!!\n");
    else
        printf("Enter popped Element is %d\n",stack[top--].key);
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Empty Stack!!!\n");
    }
    else
    {
        for(i=top;i>=0;i--)
            printf("%d\t",stack[i].key);
        printf("\n");
    }
}
int main()
{
    int choice;
    stack=(ele*)malloc(sizeof(ele));
    while(1)
    {
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            case 4:exit(0);
                break;
            default:printf("WRONG CHOICE\n");
        }
    }
    return 0;
}

