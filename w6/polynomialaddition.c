#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define COMPARE(x,y)(((x)<(y))?-1:((x)==(y))?0:1)
typedef struct polynode* polyptr;
typedef struct polynode
{
        int coef;
        int expon;
        polyptr link;
}polynode;
polyptr heada,headb,headc;
void attach (int c,int e,polyptr *ptr)
{
        polyptr temp;
        temp=(polyptr)malloc(sizeof(polynode));
        temp->coef=c;
        temp->expon=e;
        (*ptr)->link=temp;
        (*ptr)=temp;
}
void cpadd(polyptr a,polyptr b)
{
        polyptr starta,lastc;
        int sum,done=FALSE;
        starta=a;
        a=a->link;
        b=b->link;
        headc=(polyptr)malloc(sizeof(polynode));
        headc->expon=-1;
        lastc=headc;
        do
        {
                switch(COMPARE(a->expon,b->expon))
                {
                        case -1:attach(b->coef,b->expon,&lastc);
                                b=b->link;break;
                        case 1:attach(a->coef,a->expon,&lastc);a=a->link;break;
                        case 0:if(starta==a)done=TRUE;
                                else
                                {
                                        sum=a->coef+b->coef;
                                        if(sum)attach(sum,a->expon,&lastc);
                                        a=a->link;
                                                b=b->link;
                                }

                }
        }while(!done);
        lastc->link = headc;
}

int main()
{
        polyptr lasta, lastb, temp, start;
        int c, e, i, n;
        heada = (polyptr) malloc(sizeof(polynode));
        heada->expon = -1;
        lasta = heada;
        headb = (polyptr) malloc(sizeof(polynode));
        headb->expon = -1;
        lastb = headb;

        printf("How many terms in A? \n");
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
                printf("Enter coef & expon: ");
                scanf("%d%d" , &c, &e);
                attach(c, e, &lasta);
        }
        lasta->link = heada;

        printf("How many terms in B? \n");
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
                printf("Enter coef & expon: ");
                scanf("%d%d" , &c, &e);
                attach(c, e, &lastb);
        }

        lastb->link = headb;

        cpadd(heada, headb);
        printf("Polynomial A is: \n");
        for(start=heada->link; start!=heada; start = start->link)
                printf("%d+x%d +", start->coef, start->expon);
        printf("\nPolynomial B is: \n");
        for(start=headb->link; start!=headb; start = start->link)
                printf("%d+x%d +", start->coef, start->expon);
        printf("\nPolynomial C is: \n");
        for(start=headc->link; start!=headc; start = start->link)
                printf("%d+x%d +", start->coef, start->expon);
        printf("\n");
        return 0;
}

