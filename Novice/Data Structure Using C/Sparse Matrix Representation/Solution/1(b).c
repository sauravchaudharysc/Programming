#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    int row;
    int col;
    struct node *next;
};
typedef struct node NODE;
NODE* create(NODE* head,int non_zero,int row,int col)
{
    NODE *temp=head,*p;
    p=(NODE *)malloc(sizeof(NODE));
    p->info=non_zero;
    p->row=row;
    p->col=col;
    p->next=NULL;
    if(temp==NULL)
    {
        head=p;
        return head;
    }
    else
    {
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=p;
        return head;
    }
}
void display(NODE* start) 
{ 
    NODE *temp; 
    temp =start; 
  
    printf("ROW  COL  Val\n"); 
    while(temp != NULL) 
    { 
  
        printf(" %d   ", temp->row);
        printf(" %d   ", temp->col);
        printf(" %d   ", temp->info);
        temp = temp->next; 
        printf("\n"); 
    } 
    
}
int main()
{
    NODE *head=NULL;
    int rows,col,val;
    printf("Enter the no of rows :- ");
    scanf("%d",&rows);
    printf("Enter the no of columns :- ");
    scanf("%d",&col);
    int sparseMatrix[rows][col]; 
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
        printf("Enter the Value at [%d][%d]",i,j);    
        scanf("%d",&val);
        sparseMatrix[i][j]=val;
        }
    }
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < col; j++) 
            if (sparseMatrix[i][j] != 0) 
                head=create(head, sparseMatrix[i][j], i, j); 
    display(head);
}
