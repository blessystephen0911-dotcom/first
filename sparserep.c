#include <stdio.h>
typedef struct
{ int row;
int col;
int val;
}sparse;

void main()
{int i,j, m,n,nz=0;
printf("Enter order:");
scanf("%d%d",&m,&n);
int a[m][n];
printf("Enter elements:");

for(i=0;i<m;i++)
for(j=0;j<n;j++)
{scanf("%d",&a[i][j]);
if(a[i][j]!=0)
nz++;}
sparse sm[nz+1];
sm[0].row=m;
sm[0].col=n;
sm[0].val=nz;
int k=1;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
if(a[i][j]!=0)
{sm[k].row=i;
sm[k].col=j;
sm[k].val=a[i][j];
k++;}
printf("Sparse matrix representation");
printf("\nROW\tCOL\tVALUE");
for(i=0;i<k;i++)
printf("\n%d\t%d\t%d\n",sm[i].row,sm[i].col,sm[i].val);
}


