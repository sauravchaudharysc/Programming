#include<stdio.h>
#define MAX 10
int a[MAX];
int front=0,rear=-1;

  void insert(int x)
    {  
      if(rear==MAX-1)
        printf("queue is full");
      else
    {  
          if(rear==-1)
          a[++rear]=x;
      else
        {
          int i=0;
          for(i=rear;i>=0;i--)
           {
             if(a[i]>x)
                {
                    int t;
                    t=a[i+1];
                    a[i+1]=a[i];
                    a[i]=t;
                }
             else
                break;
            }
                    a[i+1]=x;
                    rear++;
        }
            
    }
}

void delete()
{
if(front>rear){
printf("Underflow");
return;}
printf("The element dequed is %d \n",a[front]);
front++;
}

void display()
{
    int i=0;
for(i=front;i<=rear;i++)
printf("%d ",a[i]);
printf("\n");
}

int main()
{  
    int choice=0,data;
    while(choice!=4)
        {
        printf("1.Entre the element in queue\n");
        printf("2.Delete element from queue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter Choice :- ");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1:
             printf("Enter data :- ");
             scanf("%d",&data);
             insert(data);
             break;
          case 2:
             delete();
             break;          
          case 3:
             display();
             break;
          case 4:
             break;
          default:
            printf("Wrong choice\n");
        }
        }
}
