#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
        int key;
}element;
typedef struct stack *stackptr;
typedef struct stack
{
        element data;
        stackptr link;
}stack;

stackptr top[MAX];
void push(int item,int i)
{
        stackptr temp;
        temp=(stackptr)malloc(sizeof(stack));
        temp->data.key=item;
        temp->link=top[i];
        top[i]=temp;
}
void pop(int i)
{
        stackptr temp=top[i];
        if(temp==NULL)
                printf("Stack %d is Empty",i);
        else
        {
                top[i]=temp->link;
                printf("Element %d popped off from stack %d",temp->data.key,i);
                free(temp);
        }
}
void display()
{
        int i;
        stackptr temp;
        for(i=0;i<MAX;i++)
        {
                printf("Stack No. %d:\n",i+1);
                if(top[i]==NULL)
                        printf("Stack empty\n");
                else
                {
                        for(temp=top[i];temp!=NULL;temp=temp->link)
                                printf("%d\t",temp->data.key);
                        printf("%d\t",temp->data.key);
                }
        }
}
int main()
{
        int stackno,choice, item;
        while(1)
        {
                printf("Enter \n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
                scanf("%d",&choice);
                if(choice!=4)
                {
                        printf("Enter stack number from 1-10\n");
                        scanf("%d",&stackno);
                }
                switch(choice)
                {
                        case 1:printf("Enter data to be inserted:");
                                scanf("%d",&item);
                                push(item,stackno-1);
                                break;
                        case 2: pop(stackno);
                                break;
                        case 3:display();
                                break;
                        case 4:printf("OPERATION COMPLETE\n");
                                        exit(0);
                }
        }
        return 0;
}

