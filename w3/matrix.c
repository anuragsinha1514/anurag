#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
if(!((p)=malloc((s))))\
{\
printf("insufficient memory\n");\
        exit(1);\
}
int **make2darray(int r,int c)
{
        int **x,i;
        MALLOC(x,r*sizeof(*x))
        for(i=0;i<r;i++)
        {
                MALLOC(x[i],(c*sizeof(int)));

        }
        return x;
}
int main()
{
        int **myarr,r,c,i,j,**myarr2,**myarr3;
        printf("enter no. of rows and column");
        scanf("%d",&r);
        scanf("%d",&c);

        myarr=make2darray(r,c);
        myarr2=make2darray(r,c);
        myarr3=make2darray(r,c);
        printf("enter elements in matrix 1");
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
                scanf("%d",&myarr[i][j]);
        printf("enter elements in matrix 2");
        for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                         scanf("%d",&myarr2[i][j]);
                for(i=0;i<r;i++)
                        for(j=0;j<c;j++)
                                myarr3[i][j]=myarr[i][j]+myarr2[i][j];
                        printf(" MATRIX 1\n");
                        for(i=0;i<r;i++)
                        {
                                for(j=0;j<c;j++)
{
                                         printf("%d\t",myarr[j][i]);
                                }
                                printf("\n");
                        }
                        printf(" MATRIX 2\n");
                        for(i=0;i<r;i++)
                        {
                                for(j=0;j<c;j++)
                                {
                                         printf("%d\t",myarr2[j][i]);
                                }
                                printf("\n");
                        }
                        printf("sum of matrix\n");
                        for(i=0;i<r;i++)
                        {
                                for(j=0;j<c;j++)
                                {
                                         printf("%d\t",myarr3[j][i]);
                                }
                                printf("\n");
                        }
                        free(myarr);
                        free(myarr2);
                        free(myarr3);
                        return 0;
}

