#include<stdio.h>
#include<conio.h>
#define MAX 20
typedef struct stack
{
int data[MAX];
int top;
}stack;
void init(stack *s);
void push(stack *s, int x);
int pop(stack *s);

void main()
{
stack s;
char x;
int op1,op2,value;
init(&s);


printf("enter the postfix expression\n");
while((x=getchar())!='\n')
{
if(isdigit(x))
{
push(&s,x-48);
}
else
{
op1=pop(&s);
op2=pop(&s);
value=evaluate(op1,op2,x);
push(&s,value);
}
}
value=pop(&s);
printf("After evaluation = %d",value);
getch();
}
int evaluate(int op1 ,int op2, int x)
{
if(x=='+')
{
return(op1+op2);
}
else if(x=='-')
{
return(op2-op1);
}
else if (x=='*')
{
return(op1*op2);
}
else if (x=='/')
{
return(op2/op1);
}
else
{
return(op2%op1);
}
}
void init(stack *s)
{
s->top=-1;
}
void push(stack *s , int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop(stack *s)
{
int x;
x= s->data[s->top];
s->top=s->top-1;
return(x);
}