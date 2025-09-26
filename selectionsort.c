#include<stdio.h>
void selectionsort(int a[],int n)
{int p,small,ind,c,temp;
for(p=0;p<n-1;p++)
{small=a[p];
ind=p;
for(c=p+1;c<n;c++)
 {if(a[c]<small)
 {small=a[c];
 ind=c;}}
temp=a[ind];
a[ind]=a[p];
a[p]=temp;}}

void read(int a[],int n)
{for(int i=0;i<n;i++)
{scanf("%d",&a[i]);}}


void print(int a[],int n)
{for(int i=0;i<n;i++)
{printf("\n%d",a[i]);}}

void main()
{int num;
printf("Enter limit:");
scanf("%d",&num);
int a[num];
printf("Enter numbers to be sorted:");
read(a,num);
selectionsort(a,num);
print(a,num);}



