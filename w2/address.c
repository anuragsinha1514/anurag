#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n){\
if(!((p)=malloc(n))){\
printf("insufficient memory");\
exit(1);}}\

int main()
{
int *p,n,x,i;
printf("enter a number :");
scanf("%d",&n);
MALLOC(p,n*sizeof(int));
for(i=0;i<n;i++)
{
scanf("%d",(p+i));
}
for(i=0;i<n;i++)

{
printf("%d\t%u\n",*(p+i),(p+i));

}
return 0;
}
