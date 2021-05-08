    #include<stdio.h>
#include<stdlib.h>
struct node{
    int row;
    int col;
    int val;
    struct node *nextrow;
    struct node *nextcol;
};
typedef struct node MLNODE;

MLNODE *form(MLNODE *head,int r,int c)
{
    MLNODE *q,*p;
    int j;
    head = (MLNODE *) malloc (sizeof(MLNODE));
   
    head->row = -1;
    head->col = -1;
    head->val = -1;    
    head->nextcol = head;
    head->nextrow = head;

        for(j=0;j<c;j++)
            {   p = head;
                while(p->nextcol!=head)
                    p=p->nextcol;
                q = (MLNODE *) malloc (sizeof(MLNODE));
                q->col = j;
                q->row = -1;
                q->val = -1;
               
                q->nextcol = p->nextcol;
                q->nextrow = q;
                p->nextcol = q;
               
            }
        for(j=0;j<r;j++)
            {   p = head;
                while(p->nextrow!=head)
                    p=p->nextrow;
                q = (MLNODE *) malloc (sizeof(MLNODE));
                q->col = -1;
                q->row = j;
                q->val = -1;
               
                q->nextrow = p->nextrow;
                q->nextcol = q;
                p->nextrow = q;
               
            }    
    return head;                
}


MLNODE *above(MLNODE *head,int r,int c)
{   MLNODE *p,*q;
   
    p = head->nextcol;
   
    while(p->col!=c)
        p = p->nextcol;
   
    do{
        q=p;
        p=p->nextrow;
       
    }while(p->row<r && p->val!=-1);
   
    return q;
}


MLNODE *left(MLNODE *head,int r,int c)
{   MLNODE *p,*q;
    p = head->nextrow;

    while(p->row!=r)
        p = p->nextrow;
    do{
        q=p;
        p=p->nextcol;
       
    }while(p->col<c && p->val!=-1);
   
    return q;
}


void display(MLNODE *head)
{
    MLNODE *p,*q;
    p = head->nextrow;
    while(p!=head)
    {   printf("\n");
        q=p->nextcol;
        while(q!=p)
        {
            printf("%d  ",q->val);
            q=q->nextcol;
        }
        p=p->nextrow;
        printf("\n");
    }
    printf("\n");
}

MLNODE *insertion(MLNODE *head,int x,int r,int c)
{
    MLNODE *q,*a,*l;
 
    q = (MLNODE *) malloc (sizeof(MLNODE));
   
    q->row = r;
    q->col = c;
    q->val = x;
   
    a = above(head,r,c);
   
    l = left(head,r,c);
   
    q->nextrow = a->nextrow;
   
    q->nextcol = l->nextcol;
   
    a->nextrow = q;
   
    l->nextcol = q;
   
   
    return head;
   
}

void deleteion(MLNODE *head,int r,int c)
{
    MLNODE *q,*a,*l;

    a = above(head,r,c);
    l = left(head,r,c);
   
    q=a->nextrow;
    if(q->row == r)
    {
        l->nextcol = q->nextcol;
        a->nextrow = q->nextrow;
       
        free(q);
    }
    else
        printf("NO value exist at this position");
}

void swap1(MLNODE *head,int r,int c)  // to swap a raw and col.
{                                       // kuch galat ho to shi krlena
    MLNODE *a,*b;
   
    {  
        MLNODE *q = head->nextrow,*p = head->nextcol;
        while(q->row!= r)
            q=q->nextrow;
        while(p->col!=c )
            p=p->nextcol;
        a=q->nextcol;
        b=p->nextrow;
        while(a!=q && b!=p)
        {
            if(a->col < b->row)
                {   insertion(head,a->val,a->col,c);
                    deleteion(head,r,a->col);
                   
                    a=a->nextcol;
                }
               
            else if(a->col > b->row)
                {   insertion(head,b->val,r,b->row);
                    deleteion(head,b->row,c);

                    b=b->nextrow;
                }
            else if(a->col == b->row)
               
                {   if(a->col != c){
                    a->val += b->val;
                    b->val = a->val - b->val;
                    a->val = a->val - b->val;
                }
                    b=b->nextrow;
                    a=a->nextcol;
                }
        }
        if(a!=q)
        {
                insertion(head,a->val,a->col,c);
                deleteion(head,r,a->col);
                a=a->nextcol;
        }
        if(b!=p)
        {
                insertion(head,b->val,r,b->row);
                deleteion(head,b->col,c);
                b=b->nextrow;
           
        }
       
    }
}

void swap(MLNODE *head,int i,int j)    // to swap two rows
{  
    MLNODE *a,*b;
   
    {  
        MLNODE *q = head->nextrow,*p = head->nextrow;
        while(q->row!= i)
            q=q->nextrow;
        while(p->row!=j )
            p=p->nextrow;
        a=q->nextcol;
        b=p->nextcol;
        while(a!=q && b!=p)
        {
            if(a->col < b->col)
                {   insertion(head,a->val,j,a->col);
                    deleteion(head,i,a->col);
                   
                    a=a->nextcol;
                }
               
            else if(a->col > b->col)
                {   insertion(head,b->val,i,b->col);
                    deleteion(head,j,b->col);

                    b=b->nextcol;
                }
            else if(a->col == b->col)
                {
                    a->val += b->val;
                    b->val = a->val - b->val;
                    a->val = a->val - b->val;
                   
                    b=b->nextcol;
                    a=a->nextcol;
                }
        }
        if(a!=q)
        {
                insertion(head,a->val,j,a->col);
                deleteion(head,i,a->col);
                a=a->nextcol;
        }
        if(b!=p)
        {
                insertion(head,b->val,j,b->col);
                deleteion(head,j,b->col);
                b=b->nextcol;
           
        }
       
    }

}


int main()
{   int r,c;
    MLNODE *head;
    head = NULL;
    printf("Enter the no of Rows and Col : ");
    scanf("%d%d",&r,&c);
    head = form(head,r,c);
    int i=1,x;
    head = insertion(head,1,0,0);
    head = insertion(head,2,0,2);
    head = insertion(head,4,1,1);
    head = insertion(head,3,1,0);   
    head = insertion(head,5,1,2);   
    head = insertion(head,6,2,1);
 
    while(i!=0)
    {
        printf("0.Exit\t1.Insert\t2.Display\t3.Delete:\t4.Swap(row and row)\n");
           scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter value: ");
                    scanf("%d",&x);
                    printf("Enter row and col: ");
                    scanf("%d%d",&r,&c);
                    head = insertion(head,x,r,c);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("Enter row and col: ");
                    scanf("%d%d",&r,&c);
                    deleteion(head,r,c);
                    break;
            case 4:
                    swap(head,0,2);
                    i = 4;
                    break;
        }
    }
   
   
}