
#include <stdio.h>
void insertionsort(int a[],int n)
{int p,key,i;
for( p=1;p<n;p++)
   {key=a[p];
     i=p-1;
   while(i>=0 && a[i]>key)
    {a[i+1]=a[i];
      i--;
  }
     a[i+1]=key;}}

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
int a[num];
printf("Enter numbers to be sorted:");
read(a,num);
insertionsort(a,num);
printf("SORTED ARRAY");
print(a,num);}



