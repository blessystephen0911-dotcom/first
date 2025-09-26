#include<stdio.h>
void simplemerge(int a[],int f,int s,int t)
{int temp[50];
int i=f,j=s,k=0;
while(i<s && j<=t)
{if(a[i]<a[j])
  temp[k++]=a[i++];
else
  temp[k++]=a[j++];
}
while(i<s)
temp[k++]=a[i++];
while(j<=t)
temp[k++]=a[j++];
for(i=f,k=0;i<=t;i++,k++)
a[i]=temp[k];
}
void mergesort(int a[],int t,int b)
{if (t<b)
{int m=(t+b)/2;
mergesort(a,t,m);
mergesort(a,m+1,b);
simplemerge(a,t,m+1,b);
}
}

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
printf("Enter elements:");
read(a,num);
mergesort(a,0,num-1);
printf("SORTED ARRAY\n");
print(a,num);}


