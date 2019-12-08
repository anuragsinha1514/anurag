#include<stdio.h>
#include<stdlib.h>
typedef struct node * nodeptr;
typedef struct node
{
        int data;
        nodeptr llink;
        nodeptr rlink;
}node;
nodeptr head;
void dinsert()
{
        int n;
        nodeptr temp;
        temp = (nodeptr)malloc(sizeof(node));
        printf("Enter the element to be inserted:");
        scanf("%d",&n);
        temp->data = n;
        temp->llink = head;
        temp->rlink = head->rlink;
        head->rlink->llink = temp;
        head->rlink = temp;
}
void ddelete()
{
        if(head->rlink==head)
                printf("List is empty\n");
        else{
        nodeptr temp;
        temp = head->rlink;
        head->rlink = temp->rlink;
        temp->rlink->llink = head;
        printf("Deleted data:%d\n",temp->data);
        free(temp);
        }
}
void printfirst()
{
        if(head->rlink==head)
                printf("List is empty\n");
        else{
        nodeptr temp;
        for(temp = head->rlink;temp!=head;temp=temp->rlink)
                printf("%d\t",temp->data);
        printf("\n");
        }
}
void printlast()
{
        if(head->rlink==head)
                printf("List is empty\n");
        else{
        nodeptr temp;
        for(temp = head->llink;temp!=head;temp=temp->llink)
                printf("%d\t",temp->data);
        printf("\n");
        }
}
int main()
{
        int c;
        head = (nodeptr)malloc(sizeof(node));
        head->llink=head;
        head->rlink=head;
        while(1)
        {
                printf("1.Insert\n2.Delete\n3.PrintRight\n4.PrintLeft\n5.Exit\nEnter your choice:");
                scanf("%d",&c);
                switch(c)
                {
                        case 1:dinsert();
                                break;
                        case 2:ddelete();
                                break;
                        case 3:printfirst();
                                break;
                        case 4:printlast();
                                break;
                        case 5:exit(0);
                }
        }
        return 0;
}

