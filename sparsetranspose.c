#include<stdio.h>
typedef struct
{
int row;
int col;
int val;
}term;

void main()
{term a[100],b[100];
int m,n,nz,i,j;
printf("Enter order of matrix:");
scanf("%d%d",&m,&n);
printf("Enter no of non zero elements:");
scanf("%d",&nz);
a[0].row=m;
a[0].col=n;
a[0].val=nz;
printf("Enter row,col,value for each non zero element:");
for(i=1;i<=nz;i++)
scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
b[0].row = a[0].col;
b[0].col = a[0].row;
b[0].val = a[0].val;
for(i=1;i<=nz;i++)
{
b[i].row=a[i].col;
b[i].col=a[i].row;
b[i].val=a[i].val;
}
for(i=1;i<nz-1;i++)
{for(j=i+1;j<nz;j++)
{(if b[i].row>b[j].row || (b[i].row>b[j].row && b[i].col>b[j].col))
{int t=b[i];
b[i]=b[j];
b[j]=t;}}}
printf("\nTRANSPOSE(ROW COL VALUE)\n");
for(i=0;i<=nz;i++)
printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
}
