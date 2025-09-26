#include<stdio.h>
#define size 5
int deque[size];
int f=-1;
int r=-1;

int isempty(){
if (f==-1 )
return 1;
else 
return 0;}

int isfull()
{if (f==(r+1)%size)
return 1;
else
return 0;
}

void insertR(int item)
{if(isfull())
printf("Deque is Full");
else if(isempty())
f=r=0;
else
r=(r+1)%size;
deque[r]=item;}

void insertF(int item)
{if(isfull())
printf("Deque is Full");
else if(isempty())
f=r=0;
else
f=(f+size-1)%size;
deque[f]=item;}

int deleteF()
{int item;
if(isempty())
printf("Deque is Empty");
else 
item=deque[f];
if(f==r)
f=r=-1;
else
f=(f+1)%size;
return item;}

int deleteR()
{int item;
if(isempty())
printf("Deque is Empty");
else 
 item=deque[r];
if(f==r)
f=r=1;
else
r=(r-1+size)%size;
return item;}

void display()
{int i;
if (isempty())
{printf("Deque is Empty");
return;}
i=f;
while(1)
{printf("%d",deque[i]);
if (i==r)
break;
i=(i+1)%size;}}


void main()
{int ele,choice;
do
{
printf("\nDOUBLE ENDED QUEUE");
printf("\n1.Insert at Rear\n2.Insert at Front\n3.Delete from Front\n4.Delete from Rear\n5.Display Queue\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);

switch(choice)
{ case 1 :{
          printf ("Enter the element to be inserted:");
          scanf("%d",&ele);
           insertR(ele);
          printf("Element inserted successfully");
          
         }
          break;
case 2: {
          printf ("Enter the element to be inserted:");
          scanf("%d",&ele);
           insertF(ele);
          printf("Element inserted successfully");
          
         }
          break;
case 3: {if(isempty())
	printf("Deque Empty");
	else
	printf("DELETING ELEMENT FROM FRONT");
         ele=deleteF();
	printf("\nDeleted element is %d",ele);}
	 break;
case 4: {if(isempty())
	printf("Deque Empty");
	else
	printf("DELETING ELEMENT FROM REAR");
         ele=deleteR();
	printf("\nDeleted element is %d",ele);}
	 break;
case 5: {printf("Current elements in deque are\n");
	display();
case 6: printf("Exiting");}
       break;
default: printf("INVALID CHOICE");
}}
while(choice!=6);
}


