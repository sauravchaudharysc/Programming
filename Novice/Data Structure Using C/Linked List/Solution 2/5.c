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
    NODE *delete_start(NODE *head)
    {
        NODE *p=head;
        int item;
        if(head==NULL)
        {
            printf("List is empty\n");
            return NULL;
        }
        item=head->info;
        head=head->next;
        printf("%d \n",item);
        free(p);
        return head;
    }
int main()
 {
    NODE *head1=NULL,*head2=NULL,*temp=NULL;
    int n,data,pos;
    int flag=0;
    printf("Enter the length of list");
    scanf("%d",&n);
    for(pos=0;pos<n;pos++)
{
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    head1=insert_end(head1,data);
}
temp=head1;
while(temp!=NULL)
{
    head2=insert_start(head2,temp->info);
    temp=temp->next;
}
int i=0;
if(n%2==0)
{
    while(i<(n/2))
    {
      if(head1->info!=head2->info)
         flag=1;
        head1=head1->next;
        head2=head2->next;
    
    i++;    
    }     
}
else
    while(i<((n/2)+1))
    {
      if(head1->info!=head2->info)
         flag=1;
        head1=head1->next;
        head2=head2->next;
    
    i++;
        
    }
if(flag==0)
    printf("Palindrome");
else
    printf("Not");
}

