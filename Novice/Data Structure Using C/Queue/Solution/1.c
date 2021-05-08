#include<stdio.h>
#define MAX 10
struct Queue
    {
        char qu[MAX];
        int front;
        int rear;
    };
typedef struct Queue at;
at bt;
int i,val;
void enqueue()
{
    if(bt.rear==MAX-1)
     printf("Queue Overflow\n");
    else
     {
        if(bt.front==-1)
        bt.front=0;
        printf("Enter the Value to Enqueue :- ");
        scanf("%d",&val);
        bt.qu[++bt.rear]=val;
     }    
}
void deque()
{
    if(bt.front==-1&&bt.rear==-1||bt.front>bt.rear)
        printf("Queue Underflow\n");
    else
     {
        val=bt.qu[bt.front];
        bt.qu[bt.front++];
        printf("The value dequed is %d\n",val);
     }
}
void display()
{
    if(bt.rear==-1||bt.rear==0)
     printf("Queue is Empty\n");
    else
     {
        for(i=bt.front;i<=bt.rear;i++)
        printf("%d",bt.qu[i]);
     }
    printf("\n"); 
}
int main ()
{
    int choice;
    bt.front=-1;
bt.rear=-1;
  printf ("*********MENU*********\n");
  do
    {
    printf ("1.Enqueue\n2.Deque\n3.Display\n4.Exit\n");
    printf ("Enter your choice :- ");
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

