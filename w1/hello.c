#include<stdio.h>
int main()
{
char s[5]="hello";
char x[]="hello";
printf("%s\n",s);
printf("size of x is %lu\n",sizeof(x));
printf("size of s is %lu\n",sizeof(s));
printf("size of int is%lu\n",sizeof (int));
return 0;
}
