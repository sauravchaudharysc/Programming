#include<stdio.h>
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
NODE *create_list(NODE *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;

    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start=insert_start(start,data);

    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=insert_end(start,data);    
    }
    return start;
}/*End of create_list()*/
    
NODE *concat( NODE *start1,NODE *start2)
{
    NODE *ptr;
    if(start1==NULL)
    {
        start1=start2;
        return start1;
    }
    if(start2==NULL)   
        return start1;
    ptr=start1;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=start2;    
    return start1;
}
    


int main()
{
    NODE *start1=NULL,*start2=NULL;
    start1=create_list(start1);
    start2=create_list(start2);
    printf("First list is  : ");
    display(start1);
    printf("Second list is  : ");
    display(start2);
    start1=concat(start1, start2);
    printf("Concatenated list is  : ");
    display(start1);
}

