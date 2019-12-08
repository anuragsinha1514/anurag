#include<stdio.h>
#include<stdlib.h>

typedef struct node * nodeptr;
typedef struct node
{
    int data;
    nodeptr link;
} node;

nodeptr first = NULL;

void insertAtStart(int x)
{
    nodeptr t = (nodeptr) malloc(sizeof(node));
    t->link = first;
    t->data = x;
    first = t;
}

void insertAtEnd(int x)
{
    nodeptr n;
    nodeptr t = (nodeptr) malloc(sizeof(node));
    t->link = NULL;
    t->data = x;
    if (first == NULL)
    {
        first = t;
        return;
    }
    for(n = first;n->link != NULL;n=n->link);
    n->link = t;
}

void delFirst()
{
    nodeptr n;
    if(first==NULL)
    {
        printf("Empty list.");
        return;
    }
    n = first->link;
    free(first);
    first = n;
}

void delLast()
{
    nodeptr n, p;
    if(first==NULL)
        {
                printf("Empty list.");
                return;
        }
    for(n = first, p = first;n->link != NULL; p = n, n=n->link);
    p->link = NULL;
    free(n);
}

void del(int x)
{
    nodeptr n, p;
    if(first==NULL)
        {
                printf("Empty list.");
                return;
        }
    for(n = first, p = first; n->data != x && n->link != NULL; p=n, n=n->link);
    if(n->data == x)
    {
        p->link = n->link;
        free(n);
    }
}

void display()
{
    nodeptr n;
    if(first==NULL)
        {
                printf("Empty list.");
                return;
        }
    for(n = first; n != NULL; n = n->link)
        printf("%d\t", n->data);
    printf("\n");
}

void main()
{
    int ch, x;
    while(1)
    {
        printf("===========================\n1. Insert at beginning\n2. Insert at end\n3. Delete first\n4. Delete last\n5. Delete first occurence of element\n6. Display all\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        printf("===========================\n");
        switch(ch)
        {
            case 1: printf("Enter element: ");scanf("%d", &x);insertAtStart(x);break;
                        case 2: printf("Enter element: ");scanf("%d", &x);insertAtEnd(x);break;
                        case 3: delFirst();break;
                        case 4: delLast();break;
                        case 5: printf("Enter element: ");scanf("%d", &x);del(x);break;
                        case 6: display();break;
                        case 7: return;
        }
    }
}

