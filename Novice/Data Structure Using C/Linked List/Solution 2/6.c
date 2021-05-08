#include <stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *next;
};
typedef struct Node NODE;
    void display(NODE *head)
    {
        NODE *p=head;
       if(p==NULL)
       printf("Empty\n");
       else
       {
        while(p!=NULL)
        {
            printf("%d \t",p->info);
            p=p->next;
        }
        printf("\n");
        }
    }
    NODE *insert_start(NODE *head,int x)
    {
        NODE *q;
        q=(NODE*)malloc(sizeof(NODE));
        q->info=x;
        q->next=head;
        return q;
    }
    NODE *insert_end(NODE *head,int x)
    {
        NODE *p=head,*q;
        q=(NODE*)malloc(sizeof(NODE));
        q->info=x;
        q->next=NULL;
        if(head==NULL)
        {
           q->next=head;
        return q;
        }
        while(p->next!=NULL)
            p=p->next;
            p->next=q;
        return head;
    }
    int main()
{
NODE *head2=NULL,*head1=NULL,*temp=NULL;
int choice,data,item,pos;
while(1)
{
    printf("1.Enter an element\n");
    printf("2.Reverse \n");
    printf("3.Display Reverse\n");
    printf("4.Normal Display\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);    
switch(choice)
        {
 case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head1=insert_end(head1,data);
            temp=head1;
         break;
 case 2:
        while(temp!=NULL)
        {
        head2=insert_start(head2,temp->info);
        temp=temp->next;
        } 
         break;
 case 3:
        display(head2);
        break;
 case 4:
        display(head1);
        break;
 default:
        printf("Enter choice correctly");
        }}
}

