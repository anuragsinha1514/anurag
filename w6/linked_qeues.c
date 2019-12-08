#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUES 10

typedef struct
{
        int key;
} element;
typedef struct queue * queueptr;
typedef struct queue
{
        element data;
        queueptr link;
} queue;
queueptr front[MAX_QUEUES], rear[MAX_QUEUES];

void push(int i, int item)
{
        queueptr temp;
        temp = (queueptr) malloc(sizeof(queue));
        temp->data.key = item;
        temp->link = NULL;
        if(front[i] == NULL)
                front[i] = temp;
        else
                rear[i]->link = temp;
        rear[i] = temp;
}

void pop(int i)
{
        queueptr temp = front[i];
        if (temp == NULL)
        {
                printf("Queue %d is empty.\n", i);
                return;
        }
        front[i] = temp->link;
        printf("Removed %d from queue %d\n", temp->data.key, i);
        free(temp);
}

void display(int i)
{
        queueptr temp = front[i];
        if (temp == NULL)
        {
                printf("Queue %d is empty.\n", i);
                return;
        }
        for(;temp != rear[i]; temp = temp->link)
                printf("%d\t", temp->data.key);
        printf("%d\n", temp->data.key);
}

int main()
{
        int ch, i, x;
        while(1)
        {
                printf("==================\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
                scanf("%d", &ch);
                if (ch == 4) return 0;
                printf("Select queue (0-9): ");
                scanf("%d", &i);
                printf("==================\n");
                switch(ch)
                {
                        case 1: printf("Enter the element: ");scanf("%d", &x);push(i, x);break;
                        case 2: pop(i);break;
                        case 3: display(i);break;
                        default: printf("Invalid. ");
                }
        }
}

