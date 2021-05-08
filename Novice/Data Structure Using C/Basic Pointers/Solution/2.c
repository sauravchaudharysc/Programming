// :) :)
// Call by Value
//No Swapping occurs because the duplicate goes inside the function.
#include <stdio.h>
int swap(int ,int );
int main()
{
    int a,b;
    printf("Enter two numbers to get swaped");
    scanf("%d%d",&a,&b);
    printf("The two numbers to get swaped are %d %d",a,b);
    swap(a,b);
    printf("\nThe two numbers after swaped are %d %d",a,b);
}
int swap(a,b)
{
    int c=a;
    a=b;
    b=c;
}

// Call by Reference
//Swapping occurs because the original values goes inside the function since the address of it is passed. Though there is no conecpt of call by reference in C it is achieved by using pointers.
#include <stdio.h>
int swap(int *,int *);
int main()
{
    int a,b;
    printf("Enter two numbers to get swaped");
    scanf("%d%d",&a,&b);
    printf("the two numbers to get swaped are %d %d",a,b);
    swap(&a,&b);
    printf("\nThe two numbers after swaped are %d %d",a,b);
}
int swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
