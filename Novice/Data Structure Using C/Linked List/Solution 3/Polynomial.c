#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int power,digit;
    struct node *next;
}node;


node* insert(node *head,int digit,int power)
{
    node *q,*p=head;
    q=(node*)malloc(sizeof(node));
    q->power=power;
    q->digit=digit;
    q->next=NULL;
    if(p==NULL)
    {
        head=q;
        return head;
    }
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    return head;
}

node* addition(node *head1,node *head2)
{
    node *top=NULL;
    int dig;
    while(head1!=NULL&&head2!=NULL)
    {
        if((head1->power)>(head2->power))
        {
           top= insert(top,head1->digit,head1->power);
            head1=head1->next;
        }
        else if((head1->power)<(head2->power))
        {
            top=insert(top,head2->digit,head2->power);
            head2=head2->next;
        }
        else
        {
            dig=(head1->digit)+(head2->digit);
            if(dig!=0){
            top=insert(top,dig,head1->power);
            head1=head1->next;
            head2=head2->next;}
        }
    }
    while(head1!=NULL)
    {
        top=insert(top,head1->digit,head1->power);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        top=insert(top,head2->digit,head2->power);
        head2=head2->next;
    }
    return top;

}
void display(node *head)
{
    while(head!=NULL)
    {
        printf("%d %d ",head->digit,head->power);
        head=head->next;
    }
}

   
int main()
{
   node *head1=NULL,*head2=NULL,*ADD;
   int k=1,power,digit,option;
   while(k){
   printf("\n1.enter data in list 1 \n2.enter data in list 2\n3.addition\n4.display\n5.exit\n");
   printf("enter your choice");
   scanf("%d",&option);
   switch(option)
   {
   case 1:
    printf("enter your digit and power");
    scanf("%d%d",&digit,&power);
    head1=insert(head1,digit,power);
    break;

   case 2:
    printf("enter your digit and power");
    scanf("%d%d",&digit,&power);
    head2=insert(head2,digit,power);
    break;

   case 3:
    ADD=addition(head1,head2);
    break;
   case 4:
    display(ADD);
    break;
   case 5:
    k=0;
   }


   }
}


   

