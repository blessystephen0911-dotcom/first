#include<stdio.h>
typedef struct
{int row,col,val;
}sparse;

void read(sparse sm[],int nz)
{int m,n;
printf("Enter the order of matrix:");
scanf("%d%d",&m,&n);
sm[0].row=m;
sm[0].col=n;
sm[0].val=nz;
printf("Enter value for ROW,COL,VAL(non zero)\n");
for(int i=1;i<=nz;i++)
scanf("%d%d%d",&sm[i].row,&sm[i].col,&sm[i].val);
}

int main()
{int nz1,nz2,totalnz;
sparse sm1[100],sm2[100],sm3[100];
printf("Enter no of non zero values in matrix 1:\n");
scanf("%d",&nz1);
read(sm1,nz1);
printf("Enter no of non zero values in matrix 2:\n");
scanf("%d",&nz2);
read(sm2,nz2);
if(sm1[0].row!=sm2[0].row ||sm1[0].col!=sm2[0].col)
{printf("Matrix Addition not Possible");
return 0;}
totalnz=nz1+nz2;
sm3[0].row=sm1[0].row;
sm3[0].col=sm1[0].col;
sm3[0].val=totalnz;
int i=1,j=1,k=1;
while(i<=nz1 &&j<=nz2)
{if(sm1[i].row==sm2[j].row && sm1[i].col==sm2[j].col)
{sm3[k].row=sm1[i].row;
sm3[k].col=sm1[i].col;
sm3[k].val=sm1[i].val+sm2[j].val;
i++;
j++;
k++;}
else if(sm1[i].row<sm2[j].row ||(sm1[i].row==sm2[j].row &&sm1[i].col==sm2[j].col))
{sm3[k]=sm1[i];
i++;
k++;}
else
{sm3[k]=sm2[j];
j++;
k++;}}
while(i<=nz1)
{sm3[k]=sm1[i];
i++;
k++;}
while(j<=nz2)
{sm3[k]=sm2[j];
j++;
k++;}
printf("Resultant Sparse Matrix\n");
printf("ROW\tCOL\tVAL\n");
for(int p=1;p<k;p++)
printf("%d\t%d\t%d\n",sm3[p].row,sm3[p].col,sm3[p].val);
}


