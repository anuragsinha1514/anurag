#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
        if(!((p)=malloc(s)))\
        {\
                printf("INSUFFICIENT MEMORY\n");\
                exit(-1);\
        }
int main()
{
        int *ip;
        float *fp;
        MALLOC(ip,sizeof(int));
        *ip=10;
        printf("INT MEMORY ALLOCATED=%d\n",*ip);
        MALLOC(fp,sizeof(float))
        *fp=20.0;
        printf("FLOAT MEMORY ALLOCATED=%f\n",*fp);
        return 0;
}



