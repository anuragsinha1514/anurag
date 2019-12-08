#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
typedef struct
{
    int k;
}stack;
stack a[MAX];
void push()
{
    int item;
    if(top>=MAX-1)
        printf("Stack is full\n");
    else
    {
        printf("Enter the element:");
        scanf("%d",&a[++top].k);
    }
}
void pop()
{
    if(top==-1)
        printf("Stack is empty\n");
    else
        printf("Item poped:%d\n",a[top--].k);
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d\t",a[i].k);
    printf("\n");
}
int main()
{
    int ch;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            case 4:exit(0);
                break;
            default:printf("Invalid choice\n");
        }
    }


    return 0;
}


