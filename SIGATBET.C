#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
int data;
struct node *next;
}node;
node* Insert_b(node *head,int x);
node* Insert_end(node *head,int x);
node* Insert_between(node *head,int x,int key);
void display(node *head);

void main()
{
node *head = NULL;
int x,ch,key;
clrscr();
do{
printf("menu\n");
printf("1.inesert at front\n2.insert at end\n3.insert at between\n4.display\n5.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1 :printf("enter data\n");
 scanf("%d",&x);
 head=Insert_b(head,x);
 break;
 case 2 :printf("enter data\n");
 scanf("%d",&x);
 head=Insert_end(head,x);
 break;
 case 3 :printf("enter data\n");
 scanf("%d",&x);
 printf("enetr after which data\n");
 scanf("%d",&key);
 head=Insert_between(head,x,key);
 break;
 case 4:
 display(head);
 break;
 case 5:
 break;
 default : printf("invalud choice\n");
}
}while(ch!=5);
getch();
}
node* Insert_b(node *head,int x)
{
node *p;
p=(node*)malloc(sizeof(node));
p->data=x;
p->next= head;
head = p;
return(head);
}
node* Insert_end(node *head,int x)
{
node *p,*q;
p=(node*)malloc(sizeof(node));
p->data=x;
p->next=NULL;
if(head==NULL)
{
head=p;
return(head);
}
else
{
q=head;
while((q->next)!=NULL)
{
q=q->next;
}
q->next=p;
return(head);
}
}
node* Insert_between(node *head,int x,int key)
{
node *p,*q;
p=(node*)malloc(sizeof(node));
p->data=x;
q=head;
while(q->data!=key && q!=NULL)
{
q=q->next;
}
if(q->data==key)
{
p->next=q->next;
q->next=p;
}
return (head);
}
void display(node *head)
{
    node *p;
    p=head;
    while((p->next)!=NULL)
    {
       printf("%d ",p->data);
       p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}