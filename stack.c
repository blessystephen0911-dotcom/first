#include<stdio.h>
#define size 2
int top=0;
int s[size];
int isempty()
{if (top==0)
return 1;
else
return 0;
}

int isfull()
{if (top>=size)
return 1;
else
return 0;
}
void push(int item)
{if(isfull())
printf("Stack is full");
else
s[top++]=item;
}
int pop()
{int item;
if(isempty())
printf("Stack is empty");
else item=s[--top];
return(item);
}

void main()
{int ele,choice;
do
{
printf("\n1.push\n2.pop\n3.isempty\n4.isfull\n5.exit");
printf("\nEnter your choice:");
scanf("%d",&choice);

switch(choice)
{ case 1:if(! isfull())
         {printf("Enter the elements to be pushed:");
          scanf("%d",&ele);
           push(ele);
          printf("Element pushed successfully");
          
         }
          break;
case 2: if(isempty())
        printf("Stack empty");
        else
        printf("\n item popped=%d",pop());
        break;
case 3: if(isempty())
        printf("Yes");
        else
        printf("Not");
        break;
case 4: if(isfull())
        printf("Yes");
        else
        printf("Not");
        break;
case 5: printf("Exiting");
       break;
default: printf("INVALID CHOICE");
}}
while(choice!=5);
}








