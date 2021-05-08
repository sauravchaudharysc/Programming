#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    unsigned frequency;
    struct Node *next;
};

typedef struct Node NODE;
NODE *createNode(char a,int f){
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=a;
    temp->frequency=f;
    temp->next=NULL;
    return temp;
}

void print(NODE *root)
{
    while(root!=NULL)
        {
            printf(" %c :  %d \n",root->data, root->frequency);
            root=root->next;
        }
}
NODE* insert(NODE *root,char a,int f){
    NODE *head=root;
    NODE *p=createNode(a,f);
    if(root==NULL){
        root =p;    
    }else{
            if(root->frequency>f){
                p->next=root;
                root=p;
            }else{
                //To check the last element priority so head->next->priority
                while(head->next!=NULL && head->next->frequency<f){
                    head=head->next;
                }
                p->next=head->next;
                head->next=p;
            }
        }    
    return root;
}
NODE *peek(NODE *root){
    return root;
}
NODE *removeNode(NODE *root)
{
    root=root->next;
    return root;
}
int isEmpty(NODE *root)
{
    return (root)==NULL;    
}
int main()
{
    NODE *head=NULL;
    
    printf("Enter the no of list to merge\n");
    int m;
    scanf("%d",&m);
    char ch;
    int freq;
    for(int i=0;i<m;i++){
        printf("Enter the character ");
        scanf("%c",&ch);
        scanf("%c",&ch);
        printf("Enter the frequency ");
        scanf("%d",&freq);
        head=insert(head,ch,freq);
    }
    while(head->next!=NULL)
    {
     NODE * t1=peek(head);
     head=removeNode(head);
     NODE * t2=peek(head);
     head=removeNode(head);
     int t= t1->frequency+t2->frequency;
      head=insert(head,'&',t);
    }
    printf("%d",head->frequency);
}