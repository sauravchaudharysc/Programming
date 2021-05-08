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
void removeDuplicates(NODE* head) 
{ 
    NODE *p= head ,*q;  
    if (p == NULL)  
       return;  
    while (p->next != NULL)  
    { 
       if (p->info == p->next->info)  
       {             
           q=p->next->next; 
           free(p->next); 
           p->next = q;   
       } 
       else /* Skips the next and Only advance if no deletion */
       { 
          p = p->next;  
       } 
    } 
} 
NODE *create_list(NODE *head)
{
int i,data,n;
printf("Enter the no of nodes");
scanf("%d",&n);
if(n==0)
return head;
head=NULL;
printf("Enter the element to insert");
scanf("%d",&data);
head=insert_start(head,data);
for(i=2;i<=n;i++)
{printf("Enter the element to insert");
scanf("%d",&data);
head=insert_end(head,data);
}
return head;
}
int main()
{
NODE *head=NULL;
int choice,data,item,pos;
while(1)
{
    printf("1.Display\n");
    printf("2.Duplicates\n");
    printf("3.Add at beginning\n");
    printf("4.Add at end\n");
	printf("5.Create a List\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

 switch(choice)
        {
        case 1:
            display(head);
         break;
        case 2:
        removeDuplicates(head);
         break;
        case 3:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head=insert_start(head,data);
         break;
        case 4:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head=insert_end(head,data);
         break;
  		case 5:
  		    head=create_list(head);
  		    break;
        default:
        printf("Wrong choice\n");
}/*End of switch*/
}/*End of while*/
return 0;
}


