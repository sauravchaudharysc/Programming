#include<stdio.h>
#include<string.h>
#define MAX 100
int top=-1;
char st[MAX],d[MAX],val,s[MAX];
void push(char val)
{
    if(top==MAX-1)
     printf("Stack Overflow");
    else
      {
        top++;
        st[top]=val;
      }
}
char pop()
{
    if(top==-1)
     printf("Stack Underflow");
    else
      {
        val=st[top];  
        top--;
        return val;
      }
}
int compare(char c)
{
    if(c=='(')
    return 0;
    else if(c=='+' || c=='-')
    return 1;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='$' || c=='^')
    return 3;
    else 
    return -1;
    
}
int main()
{
    printf("Enter the expression :- ");
    scanf("%s",d);
    char e;
    int i,j=0;
    for( i=strlen(d)-1;i>=0;i--)
    {
        if(isalnum(d[i]))
          {
              s[j]=d[i];
              j++;
          }
        else if(d[i]==')')
          push(d[i]);
        else if(d[i]=='(')
         while((e=pop())!=')'){
            s[j]=e;
            j++;}
        else
            {
                while(compare(st[top])>compare(d[i]))
                    {s[j]=pop();
                    j++;}
                push(d[i]);
            }
}            
    while(top!=-1){
    s[j]=pop();
    j++;}
    for(i=j-1;i>=0;i--)
    printf("%c",s[i]);
}




