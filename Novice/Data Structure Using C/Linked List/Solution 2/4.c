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
	NODE *create_list(NODE *head)
    {
        int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        head=NULL;
        if(n==0)
        return head;
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        head=insert_start(head,data);
        for(i=2; i<=n; i++)
        {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        head=insert_end(head,data);
        }
        return head;
    }
   
   NODE *deleteAlt(NODE *head) 
{ 
    if (head == NULL) 
        return; 
  
    /* Initialize prev and node to be deleted */
    NODE *prev = head; 
    NODE *node = head->next; 
  
    while (prev != NULL && node != NULL) 
    { 
        /* Change next link of previous node */
        prev->next = node->next; 
  
        /* Free memory */
        free(node); 
       /* Update prev and node */
        prev = prev->next; 
        if (prev != NULL) 
            node = prev->next; 
    } 
    return head;
} 
        
int main()
{
NODE *head=NULL;
int choice,data,x;
while(1)
{ 
    printf("\n******************MAIN MENU******************\n");
    printf("1.Create List\n");
    printf("2.Display\n");
    printf("3.Delete Alternate      \n");
    printf("4.Exit      \n");
 	printf("Enter your choice : ");
    scanf("%d",&choice);

 switch(choice)
        {
        case 1:
            head=create_list(head);
         break;
        case 2:
            display(head);
         break;
        case 3:
            head=deleteAlt(head);
         break;
        case 4:
        exit(0);
        break; 
    	default:
    		printf("Enter a correct choice");
    		break;
    		}
  }
 }  			     
    
