#include<stdio.h>
void binary(int a[], int n,int e)
{int f=0,  t=0,b=n-1,m;
while(t<=b)
{m=(t+b)/2;
if(e==a[m])
{ f=1;
  break;}
else
  if(e<a[m])
   b=m-1;
  else
   t=m+1;}
if(f==1)
printf("Element found at position %d",m+1);
else 
  printf("Element not found");
}


void main()
{int n,e,i;
printf("Enter limit:");
scanf("%d",&n);
printf("Enter elements:");
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter element to be found:");
scanf("%d",&e);
binary(a,n,e);
} 
 
