#include<stdio.h>
#include <ctype.h>

#define size 100
int top=-1;
char s[size];


void push(char c)
{
	if (top<size-1)
          s[++top]=c;
	else
	  printf("Stack is full");
}

char pop()
{
	if(top==-1)
	{
 		printf("Stack is empty");
         	return'\0';
	}
        else
		return s[top--];
}

int inp(char op)
{
	switch(op)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^': return 5;
		case '(': return 0;
	}
}

void main()
{
	int i=0,j=0;
	char x,c;
	char input[50],postfix[50];
	printf("Enter infix expression:");
	scanf("%s",input);
	while(input[i]!='\0')
	{
		c=input[i];
		if(c=='(')
			push (c);
		else
			if(isalnum(c))
				postfix[j++]=c;
			else
				if(c==')')
					while((x=pop())!='('&&x!='\0')
						postfix[j++]=x;
				else
				{
					while(top!=-1&&(inp(s[top])>=inp(c)))
						postfix[j++]=pop();
					push(c);
				}
				i++;
	}
	while (top!=-1)
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("\n Postfix expression:%s",postfix);
}


