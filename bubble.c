#include<stdio.h>
void bubblesort(int a[],int n)
{ int p,c,t;
for( p=1;p<n;p++)
  for(c=0;c<n-p;c++)
    {
     if (a[c]>a[c+1])
      {t=a[c];
       a[c]=a[c+1];
       a[c+1]=t;}
}
}
void printsort(int a[],int n)
{int i;
printf("\nSORTED ARRAY");
for(i=0;i<n;i++)
 printf("\n%d",a[i]);

}


void main()
{int n,i,t;
printf("Enter limit:");
scanf("%d",&n);
printf("Enter elements:");
int a[n];
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
bubblesort(a,n);
printsort(a,n);
}
 
