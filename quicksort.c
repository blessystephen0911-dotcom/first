#include <stdio.h>
void swap(int *a,int *b)
{int t;

t=*a;
*a=*b;
*b=t;}


int partition(int a[],int left,int right)
{int key=a[left],i=left+1,j=right;
do
{ while(i<right && a[i]<key)
i++;
while (j>left && a[j]>key)
j--;
if(i<j)
swap(&a[i],&a[j]);
}while (i<j);
swap(&a[left],&a[j]);
return j;
}

void quicksort(int a[],int left,int right)
{int pos;
if (left<right)
  {pos=partition(a,left,right);
quicksort(a,left,pos-1);
quicksort(a,pos+1,right);
}}

void read(int a[],int n)
{for(int i=0;i<n;i++)
{scanf("%d",&a[i]);}}



void print(int a[],int n)
{
for(int i=0;i<n;i++)
{printf("\n%d",a[i]);}}

void main()
{int num;
printf("Enter limit:");
scanf("%d",&num);
int a[50];
printf("Enter elements:");
read(a,num);
 int left=0;
int right=num-1;
quicksort(a,left,right);
printf("SORTED ARRAY\n");
print(a,num);}



