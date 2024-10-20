

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *next;
}node;

node* Insert_b(node *head,int x);
void display(node *head);

void main()
{
node *head=NULL;
int x,ch;
clrscr();
do{
printf("menu\n");
printf("1.insert at begining\n2.display\n3.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1 :printf("enter data\n");
 scanf("%d",&x);
 head=Insert_b(head,x);
 break;
 case 2:
 display(head);
 break;
 case 3:
 break;
 default : printf("invalud choice\n");
}
}while(ch!=3);

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