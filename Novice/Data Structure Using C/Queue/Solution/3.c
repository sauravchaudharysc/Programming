#include<stdio.h>
#define MAX 10
struct Queue{
int qt[MAX];
int front;
int rear;
};
int val;
struct Queue qu;
void insertRear()
{
	if(qu.rear==(MAX-1))
     	printf("Queue Overflow");
	else
	  {
		printf("Enter The Data To Enqueu");
		scanf("%d",&val);
		qu.qt[++(qu.rear)]=val;
      }
}

void insertFront()
{
	if(qu.front==0)
     	printf("Queue Overflow");
	else
	  {
		printf("Enter The Data To Enqueu");
		scanf("%d",&val);
		qu.qt[--(qu.front)]=val;
      }
}

void deleteRear()
{
    if(qu.front>qu.rear)
        printf("Queue Underflow");
    else
      {
        printf("The Element dequed is %d",qu.qt[qu.rear]);
        qu.qt[qu.rear--];
      }
}
void deleteFront()
{
    if(qu.front>qu.rear)
        printf("Queue Underflow");
    else
      {
        printf("The Element dequed is %d",qu.qt[qu.front]);
        qu.qt[qu.front++];
      }
}
void display()
{
    if(qu.front>qu.rear)
        {
          printf("Queue is empty");
        }
    else
        {
        int i;
          for( i=qu.front;i<=qu.rear;i++)
          printf("%d ",qu.qt[i]);
        }
}

int main()
{
    qu.front=0,qu.rear=-1;
    int option;
    while(option!=6)
    {
        printf("\n1.Insert From Front\n2.Insert From Rear\n3.Delete From Front\n4.Delete From Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            insertFront();
            break;

        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("Enter Correct Choice");
        }
    }
}





























