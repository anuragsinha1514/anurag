#include<stdio.h>
#define MAX_COL 100
#define MAX_TERMS 100
typedef struct{
        int row;
        int col;
        int val;
}terms;
terms a[MAX_TERMS],b[MAX_TERMS];
void transpose(terms a[],terms b[]){
        int row_terms[MAX_COL]={0},start_pos[MAX_COL];
        int i,j,num_col=a[0].col,num_terms=a[0].val;
        b[0].val=a[0].val;
        if(num_terms>0){
        for(i=1;i<=num_terms;i++)
                row_terms[a[i].col]++;
        start_pos[0]=1;
        for(i=1;i<=num_col;i++)
                start_pos[i]=start_pos[i-1]+row_terms[i-1];
        for(i=1;i<=num_terms;i++){
                j=start_pos[a[i].col]++;
                b[j].row=a[i].col;
                b[j].col=a[i].row;
                b[j].val=a[i].val;
        }
        }
}
int main(){
        int r,c,n;
        printf("enter number of rows , columns , elements \n");
        scanf("%d%d%d",&r,&c,&n);
        a[0].row=r;
        a[0].col=c;
        a[0].val=n;
        int i,j;
        printf("enter matrix elements along with positions\n");
        for(i=1;i<=n;i++){
                scanf("%d",&a[i].row);
                scanf("%d",&a[i].col);
                scanf("%d",&a[i].val);
        }
        printf("matrix accepted \ntransfer to transpose()\n");
        transpose(a,b);
        printf("transpose matrix\nrow\tcol\tval\n");
        for(i=1;i<=n;i++)
                printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);

        return 0;
}
