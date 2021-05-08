#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int top = -1;

char st[MAX], d[MAX], val, s[MAX];

char a[20][20], b[20];

void
pusha (char x[]) 
{
  
top++;
  
strcpy (a[top], x);

} 
char *

popa () 
{
  
return (a[top--]);

}


void
push (char val) 
{
  
if (top == MAX - 1)
    
printf ("Stack Overflow");
  
  else
    
    {
      
top++;
      
st[top] = val;
    
}

}


char
pop () 
{
  
if (top == -1)
    
printf ("Stack Underflow");
  
  else
    
    {
      
val = st[top];
      
top--;
      
return val;
    
}

}


int
compare (char c) 
{
  
if (c == '(')
    
return 0;
  
  else if (c == '+' || c == '-')
    
return 1;
  
  else if (c == '*' || c == '/')
    
return 2;
  
  else if (c == '$' || c == '^')
    
return 3;
  
  else
    
return -1;

 
}


int
main () 
{
  
char s[30], x[30], y[30], e[30], c[2];
  
int i, j = 0, option;
  
printf ("*************Main Menu*************\n");
  
printf
    ("\t1.Infix To Postfix\n\t2.Infix To Prefix\n\t3.Postfix To Infix\n\t4.Postfix To Prefix\n\t5.Prefix To Infix\n\t6.Prefix To Postfix\n");
  
scanf ("%d", &option);
  
printf ("Enter the expression :- ");
  
scanf ("%s", d);
  
char ea;
  
switch (option)
    
    {
    
case 1:
      
for (i = 0; i < strlen (d); i++)
	
	{
	  
if (isalnum (d[i]))
	    
	    {
	      
s[j] = d[i];
	      
j++;
	    
}
	  
	  else if (d[i] == '(')
	    
push (d[i]);
	  
	  else if (d[i] == ')')
	    
	    {
	      
while ((ea = pop ()) != '(')
		
		{
		  
s[j] = ea;
		  
j++;
		
}
	    
}
	  
	  else
	    
	    {
	      
while (compare (st[top]) >= compare (d[i]))
		
		{
		  s[j] = pop ();
		  
j++;
		}
	      
push (d[i]);
	    
}
	
}
      
while (top != -1)
	{
	  
s[j] = pop ();
	  
j++;
	}
      
printf ("The Postfix expression is :- ");
      
for (i = 0; i < j; i++)
	
printf ("%c", s[i]);
      
break;
    
case 2:
      
for (i = strlen (d) - 1; i >= 0; i--)
	
	{
	  
if (isalnum (d[i]))
	    
	    {
	      
s[j] = d[i];
	      
j++;
	    
}
	  
	  else if (d[i] == ')')
	    
push (d[i]);
	  
	  else if (d[i] == '(')
	    
	    {
	      
while ((ea = pop ()) != ')')
		
		{
		  
s[j] = ea;
		  
j++;
		
}
	    
}
	  
	  else
	    
	    {
	      
while (compare (st[top]) > compare (d[i]))
		
		{
		  s[j] = pop ();
		  
j++;
		}
	      
push (d[i]);
	    
}
	
}
      
while (top != -1)
	{
	  
s[j] = pop ();
	  
j++;
	}
      
printf ("The Prefix expression is :- ");
      
for (i = j - 1; i >= 0; i--)
	
printf ("%c", s[i]);
      
break;
    
case 3:
      
for (i = 0; i < strlen (d); i++)
	
	{
	  
c[0] = d[i];
	  
c[1] = '\0';
	  
e[0] = '(';
	  
e[1] = '\0';
	  
 
if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/'
		 || d[i] == '^')
	    
	    {
	      
strcpy (x, popa ());
	      
strcpy (y, popa ());
	      
strcat (e, y);
	      
strcpy (y, e);
	      
strcat (y, c);
	      
strcat (y, x);
	      
strcat (y, ")");
	      
pusha (y);
	    
}
	  
	  else
	    
	    {
	      
strcpy (x, c);
	      
pusha (x);
	    
}
	
}
      
printf ("The expression is :- ");
      
printf ("%s", popa ());
      
break;
    
case 4:
      
for (i = 0; i < strlen (d); i++)
	
	{
	  
c[0] = d[i];
	  
c[1] = '\0';
	  
if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/')
	    
	    {
	      
strcpy (x, popa ());
	      
strcpy (y, popa ());
	      
strcat (c, y);
	      
strcpy (y, c);
	      
strcat (y, x);
	      
pusha (y);
	    
}
	  
	  else
	    
	    {
	      
strcpy (x, c);
	      
pusha (x);
	    
}
	
}
      
printf ("%s", popa ());
      
break;
    
case 5:
      
for (i = strlen (d) - 1; i >= 0; i--)
	
	{
	  
c[0] = d[i];
	  
c[1] = '\0';
	  
e[0] = '(';
	  
e[1] = '\0';
	  
 
if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/')
	    
	    {
	      
strcpy (x, popa ());
	      
strcpy (y, popa ());
	      
strcat (e, x);
	      
strcpy (x, e);
	      
strcat (x, c);
	      
strcat (x, y);
	      
strcat (x, ")");
	      
pusha (x);
	    
}
	  
	  else
	    
	    {
	      
strcpy (x, c);
	      
pusha (x);
	    
}
	
}
      
printf ("The expression is :- ");
      
printf ("%s", popa ());
      
break;
    
case 6:
      
for (int i = strlen (d) - 1; i >= 0; i--)
	
	{
	  
c[0] = d[i];
	  
c[1] = '\0';
	  
if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/')
	    
	    {
	      
strcpy (x, popa ());
	      
strcpy (y, popa ());
	      
strcat (y, c);
	      
strcat (x, y);
	      
pusha (x);
	    
}
	  
	  else
	    
	    {
	      
strcpy (x, c);
	      
pusha (x);
	    
}
	
}
      
printf ("%s", popa ());
      
break;
    
}

}
