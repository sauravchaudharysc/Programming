#include <stdio.h>
#define MAX 10
int i, rear =0 , front = 0, val, choice;
int qt[MAX];
void enqueue ()
{
  if (((rear+1)%MAX)==front)
    printf ("\nQueue Oveflow\n");
  else
    {
      printf ("Enter the Value to Enqueue :- ");
      scanf ("%d", &val);
      rear++;
      rear=(rear)%MAX;
      qt[rear]=val;
    }
}

void deque ()
{
  if (front==rear)
    printf ("\nQueue Underflow\n");
  else
    {
      front++;
      front=(front)%MAX;
      val = qt[front];
      printf ("The Value Dequed is %d\n", val);
    }
}

void display ()
{
  if (front==rear)
    printf ("Queue is empty");
  else
    for (i=front+1;i!=(rear+1)%MAX;i=(i+1)%MAX)
      {
	printf ("%d\t", qt[i]);
      }
    printf("\n");  
}

int main ()
{
  printf ("*********MENU*********\n");
  do
    {
    printf ("1.Enqueue\n2.Deque\n3.Display\n4.Exit\n");
    printf ("Enter your choice\n");
    scanf ("%d", &choice);  
      switch (choice)
	{
	case 1:
	  enqueue ();
	  break;
	case 2:
	  deque ();
	  break;
	case 3:
	  display (); 
	  break;
	case 4:
	  break;				  
	default:
	  printf ("Enter Correct Choice\n");
	  break;
	}
    }
  while (choice != 4);
}


