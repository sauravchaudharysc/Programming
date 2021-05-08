#include <stdio.h>
#include<string.h>
#define MAX 100
char st[MAX];
int top=-1,val;
void push(int val)
{
  st[++top]=val;
}
int pop()
{
   return (st[top--]); 
}

int main()
{
    char s[20];
    int i,num,n1,n2,n3;
    printf("Enter the postfix expression to evaluate(\"Restriction Only Number between 0 and 9\")\n");
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
            {   
               num=s[i]-48;
               push(num);    
            }
        else
            {
                n1=pop();
                n2=pop();
                switch(s[i])
                {
                 case '+':
                      n3=n1+n2;
                    break;
                 case '-':
                      n3=n2-n1;
                    break;
                 case '*':
                      n3=n1*n2;
                    break;
                 case '/':
                      n3=n2/n1;
                }
             push(n3);
            }
            
    }
    printf("The evaluated value is %d",pop());
}

