#include<stdio.h>
#include<conio.h>
#define MAX 20
typedef struct queue
{
int data[MAX];
int f,r;
}queue;
void init(queue *q);
void enqueue(queue *q,int x);
int dequeue(queue *q);
void display(queue *q);
int empty(queue *q);
int full(queue *q);
void main()
{
int choice,x;
queue q;
init(&q);
clrscr();
do{
printf("menu\n");
printf("enter your choice\n");
printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enetr element\n");
scanf("%d",&x);
if(!full(&q))
{
enqueue(&q,x);
}
else
{
printf("queue is full\n");
}
break;
case 2:
if(!empty(&q))
{
x=dequeue(&q);
printf("dequeued element is %d\n",x);
}
else
{
printf("queue is empty\n");
}
break;
case 3:display(&q);
break;
case 4 :break;
default : printf("invalid choice\n");
}
}while(choice!=4);
getch();
}
void init(queue *q)
{
 q->f=-1;
 q->r=-1;
}
void enqueue(queue *q,int x)
{
if(q->r==-1)
{
 q->f=q->r=0;
 q->data[q->r]=x;
}
else
{
 q->r=(q->r+1)%MAX;
 q->data[q->r]=x;
}
}
int dequeue(queue *q)
{
int x;
x=q->data[q->f];
if(q->r==q->f)
{
q->r=q->f=-1;
}
else
{
q->f=(q->f+1)%MAX;
}
return (x);
}
int empty(queue *q)
{
if( q->r==-1)
{
return (1);
}
else
{
return (0);
}
}
int full(queue *q)
{
if(q->r==MAX-1)
{
return (1);
}
else
{
return (0);
}
}
void display(queue *q)
{
int i;
i=q->f;
while(i!=q->r)
{
 printf("%d ",q->data[i]);
  i=(i+1)%MAX;
}
printf("%d",q->data[i]);
printf("\n");
}