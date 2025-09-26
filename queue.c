#include<stdio.h>
#define size 5
int queue[size];
int f=-1;
int r=-1;
int isempty(){
if (f==-1 )
return 1;
else 
return 0;}

int isfull()
{if ((r+1)==f)
return 1;
else
return 0;
}

void insert(int item)
{if(f==-1)
r=f=0;
else
r=(r+1)%size;
queue[r]=item;
}
int delete()
{if(!isempty());
int item=queue[f];
if(f==r)
f=r=-1;
else
f=(f+1)%size;
return item;
}
void main()
{int ele,choice;
do
{
printf("\n1.Insert\n2.Delete\n3.peek\n4.Status\n5.exit");
printf("\nEnter your choice:");
scanf("%d",&choice);

switch(choice)
{ case 1:{if(!isfull())
          printf ("Enter the element to be inserted:");
          scanf("%d",&ele);
           insert(ele);
          printf("Element inserted successfully");
          
         }
          break;
case 2: if(isempty())
        printf("Queue empty");
        else
       { ele=delete();
	printf("Deleted Element is %d",ele);}
        break;
case 3: if(isempty())
        printf("Queue Empty");
        else
        printf("Not Empty!!");
        break;
case 4: if(isfull())
        printf("full");
        else
        printf("Not full");
        break;
case 5: printf("Exiting");
       break;
default: printf("INVALID CHOICE");
}}
while(choice!=5);
}


