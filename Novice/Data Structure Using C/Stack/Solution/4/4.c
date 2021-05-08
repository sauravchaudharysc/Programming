#include<stdio.h>
#define MAX 100
int st[MAX];
int option,val,top1=-1,top2=MAX;
void push()
{ 
    printf("Enter the stack number you want to push(1 or 2)\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        if(top1==top2)
        printf("Stack Overflow");
        else
        {
        printf("Enter the number you want to get push\n");    
        scanf("%d",&val);
        st[++top1]=val;   
        }
        break;
        case 2:
        if(top2==top1)
        printf("Stack Overflow");
        else
        {
        printf("Enter the number you want to get push\n");    
        scanf("%d",&val);    
        st[--top2]=val;
        }
        break;
        
    } 
}
int pop()
{ 
    printf("Enter the stack number you want to pop(1 or 2)\n");
    scanf("%d",&option);
    switch(option)
    {
     case 1:
        if(top1==-1)
         printf("Underflow");
        else
            {
                val=st[top1];
                top1--;
                return val;
            }
     break;    
     case 2:
        if(top2==MAX)
          printf("Stack Underflow");
        else
          {
            val=st[top2];
            top2++;
          }
     break;
    } 
}
void display()
{
    printf("Enter the stack number you want to display(1 or 2)\n");
    scanf("%d",&option);
    switch(option)
    {
     case 1:
     printf("The Elements in stack 1 are:- \n");
     for(int i=top1;i>=0;i--)
     printf("%d\t",st[i]);
     break;
     case 2:
     printf("The Elements in stack 2 are:- \n");
     for(int i=top2;i<MAX;i++)
     printf("%d\t",st[i]);
     break;
    }
    printf("\n");
}

int main()
{
    int choice,k=1;
printf("*************To Implement Two Stacks In a Single Array*************");
while(k)
{
printf("\n\t\t\t1.Push   \t2.Pop\n\t\t\t3.Display\t4.Exit\n");
printf("Enter your Choice :- ");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;

case 2:
pop();
printf("The element poped is %d",val);
break;

case 3:
display();
break;

case 4:
k=0;

}
}

}