#include <stdio.h>
#include<conio.h>
#define MAX 20

typedef struct stack
{
int data[MAX];
int top;
}stack;
int full(stack *s);
void push(stack *s,int x);
int empty(stack *s);
int pop(stack *s);
void display(stack *s);
void init(stack *s);

void main()
{
int choice,x;
stack s;
init(&s);
do{
printf("Menu\n");
printf("enetr your choice\n");
printf("1.push\n2.pop\n3.dispaly\n4.exit\n");
printf("enetr your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enetr element\n");
scanf("%d",&x);
if(!full(&s))
{
push(&s,x);
}
else
{
printf("oberflow\n");
}
break;
case 2:
if(!empty(&s))
{
x=pop(&s);
printf("the data poped is=%d\n",x);
}
else
{
printf("stack is empty\n");
}
break;
case 3:  display(&s);
break;
case 4:
break;
default:printf("invalid choice\n");
}
}while(choice!=4);
getch();
}
void init(stack *s)
{
s->top=-1;
}
int full(stack *s)
{
if(s->top==MAX-1)
{
return(1);
}
else{
return(0);
}
}
int empty(stack *s)
{
if(s->top==-1)
{
return(0);
}
else
{
return(0);
}
}
void push(stack *s, int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop(stack *s)
{
int x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}
void display(stack *s)
{
int i;
for(i=s->top;i>=0;i--)
{
printf("%d ",s->data[i]);
}
printf("\n");
}
