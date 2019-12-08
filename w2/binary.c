#include<stdio.h>
#define COMPARE(x,y)(((x)>(y))?1:((x)==(y))?0:-1)
int bsearch(int a[],int k,int b,int e);
int main()
{
        int n;
printf("Enter the size\n");
scanf("%d",&n);
int p,k,a[n],i,b,e;
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
        scanf("%d",&a[i]);
}
printf("Enter the key\n");
scanf("%d",&k);
b=0;
e=n;
p=bsearch(a,k,b,e);
if(p==-1)
        printf("key not found\n");
else
        printf("key found in position %d\n",p+1);
}
int bsearch(int a[],int k,int b,int e)
{
int m;
if(b<=e)
{
m=(b+e)/2;
switch(COMPARE(a[m],k))
{
case1:return bsearch(a,k,b,m-1);
case0:return m;
break;
case 1:return bsearch(a,k,m+1,e);
break;
}
}
else
return -1;
}

