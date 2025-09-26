#include<stdio.h>
void linearsearch(int a[],int n,int ele)
{int i,f=0;
for(i=0;i<n;i++){
if(a[i]==ele)
{
 f=1;
break;
}
else
 f=0;}
if(f==1)
 printf("Element found at position %d",i+1);
else
 printf("Element not found");
}
 
void main()
{int i, n,e;
 printf("Enter limit:");
 scanf("%d",&n);
 printf("Enter the elements:");
 int a[n];
 for(i=0;i<n;i++)
scanf("%d",&a[i]);
 printf("Enter element to be searched:");
 scanf("%d",&e);
linearsearch(a,n,e);
}
