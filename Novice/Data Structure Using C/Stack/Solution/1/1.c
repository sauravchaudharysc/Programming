#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top;
    int capacity;   
    int *arr;
};
   typedef struct Stack stk; //To reduce name
   
//Dynamic Memory
stk* create_stack(int n)
{
stk *s=(stk*)malloc(sizeof(stk));
s->top=-1;
s->capacity=n;
s->arr=(int*)malloc(n*sizeof(int));
return s;
}

void push(stk *s,int new_data)
{
 if(s->top==s->capacity-1)
    printf("Stack Overflow\n");
 else
    {
        s->top++;
        s->arr[s->top]=new_data;
    }
}

int pop(stk *s)
{
 if(s->top==-1)
    printf("Stack Underflow\n");
 else
    {
        int item;
        item=s->arr[s->top];
        s->top--;
        printf("The Poped element is %d\n",item);
    }
}

int main()
{
    int data, n,option;
    printf("Enter the size of the stack :-");
    scanf("%d",&n);
    stk *s=create_stack(n);
    printf("\n\t******MAIN MENU******");
    printf("\n1.Push\t\t\t2.Pop\n3.Display\t\t4.Exit\n");
  while(option!=4)
        {
            printf("Enter your choice :- ");
            scanf("%d",&option);
                switch(option)
                    {
                        case 1:
                         printf("Enter data to push :- ");
                         scanf("%d",&data);
                         push(s,data);
                         break;
                        case 2:
                         pop(s);
                         break;
                        case 3:
                         for(int i=s->top;i>=0;i--)
                         printf("%d ",s->arr[i]);
                         break;
                    }
        }
}