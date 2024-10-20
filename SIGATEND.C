#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
int data;
struct node *next;
}node;

node* Insert_end(node *head,int x);
void display(node *head);

void main()
{
int x,ch;
clrscr();
do{
printf("menu\n");
printf("1.insert at END\n2.display\n3.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1 :printf("enter data\n");
 scanf("%d",&x);
 head=Insert_end(head,x);
 break;
 case 2:
 display(head);
 break;
 case 3:
 break;
 default : printf("invalud choice\n");
}
}while(ch!=3);
getch();
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