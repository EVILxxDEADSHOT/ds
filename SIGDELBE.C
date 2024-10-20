#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *next;
}node;
node* delete_b(node *head);
node* Insert_b(node *head,int x);
void display(node *head);

void main()
{
node *head=NULL;
int x,ch;
clrscr();
do{
printf("menu\n");
printf("1.insert at begining\n2.delte at begining\n3.display\n4.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1 :printf("enter data\n");
 scanf("%d",&x);
 head=Insert_b(head,x);
 break;
 case 2:
 head=delete_b(head);
 break;
 case 3:
 display(head);
 break;
 case 4:
 break;
 default : printf("invalud choice\n");
}
}while(ch!=4);
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
node* delete_b(node *head)
{
node *p;
p=head;
head=head->next;
free(p);
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