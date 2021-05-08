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
  NODE* merge(NODE *head1,NODE *head2)
    {
       NODE *start=NULL;
       while(head1!=NULL&&head2!=NULL)
       {
           if(head1->info<=head2->info)
           {
               start=insert_end(start,head1->info);
               head1=head1->next;
           }
           else
           {
               start=insert_end(start,head2->info);
               head2=head2->next;
           }
       }
       while(head1!=NULL)
       {
           start=insert_end(start,head1->info);
           head1=head1->next;
       }
       while(head2!=NULL)
       {
           start=insert_end(start,head2->info);
           head2=head2->next;
       }
       return start;
    }

    int main()
{
NODE *head1=NULL,*start=NULL,*head2=NULL;
int choice,data;
while(1)
{
    printf("1.Push an element in 1\n");
    printf("2.Push an element in 2 \n");
    printf("3.Display 1 \n");
    printf("4.Display2 \n");
    printf("5.Merge \n");
        printf("6.Display \n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
switch(choice)
        {
 case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head1=insert_end(head1,data);
         break;
 case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head2=insert_end(head2,data);
         break;
 case 3:
        display(head1);
        break;
 case 4:
        display(head2);
        break;
 case 5:
        start=merge(head1,head2);
        break;
 case 6:
        display(start);
        break;
    default:
        printf("Enter choice correctly");
        }}
}

