#include<stdio.h>
#include<string.h>
#define max 100
char s[max];
int top=-1;
void push (char c)
{if (top<max-1)
s[++top]=c;
else
printf("Stack overflow");
}

int pop()
{if(top==-1)
{printf("Stack is empty");
return '\0';}
else
{ int temp=s[top];
top--;
return temp;}
}

void revstring(char str[100])
{int i;

int len=0;
while(str[len]!='\0')
{push(str[len]);
len++;}
for(i=0;i<len;i++){
str[i]=pop();
str[len]='\0';
}}

void main()
{int i;
char str[max];
printf("Enter a String:");

scanf("%s",str);
revstring(str);
printf("Reversed string is %s",str);
}





