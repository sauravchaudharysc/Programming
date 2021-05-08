#include <stdio.h>
int s[100],top[50],min[50],max[50];
int i,size;

void init(int size,int ns)
{
    for(i=0;i<ns;i++)
    {
        top[i]=(i*size)-1; 
    }
}
void push(int ele,int stkn)
{
    if(top[stkn-1]==(((stkn-1)*size)+size-1))
      printf("Overflow \n");
    else
    {
            s[++top[stkn-1]]=ele;
            
            
    } 
}
void pop(int stkn)
{
    if(top[stkn-1]==(((stkn-1)*size)-1))
    printf("Underflow \n");
    else
    {
        int nr;
        printf("The Poped elemenet from %d stack is %d\n",stkn,s[top[stkn-1]--]);
    }
 
}

void display(int stkn)
{
    for(i=((stkn-1)*size);i<=top[stkn-1];i++)
    printf("%d ",s[i]);
    printf("\n");
    
}

int main() {
    int ele,ch,skn;
    int ns;
    printf("Enter the number of Stacks\n");
    scanf("%d",&ns);
    size = 10/ns;
    init(size,ns);
    do{
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the stack number :");
                scanf("%d",&skn);
                printf("Enter the element to push  :");
                scanf("%d",&ele);
                push(ele,skn);
                break;
            case 2 : printf("Enter the stack number to pop :");
                     scanf("%d",&skn);
                     pop(skn);
                break;
            case 3: printf("Enter the stack number you want to display :");
                scanf("%d",&skn);
                display(skn);
                break;
            case 4 : printf("you exited");
                break;
            default : printf("enter a valid choice\n");
        }
    }
    while(ch!=4);
    return 0;
}

