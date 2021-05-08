// :) :)
//By addition and suctraction
#include <stdio.h>
int swap(int ,int );
int main()
{
    int a,b;
    printf("Enter two numbers to get swaped");
    scanf("%d%d",&a,&b);
    printf("The two numbers to get swaped are %d %d",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nThe two numbers after swaped are %d %d",a,b);
}

//By multiplication and division
#include <stdio.h>
int swap(int ,int );
int main()
{
    int a,b;
    printf("Enter two numbers to get swaped");
    scanf("%d%d",&a,&b);
    printf("The two numbers to get swaped are %d %d",a,b);
    a=a*b;
    b=a/b;
    a=a/b;
    printf("\nThe two numbers after swaped are %d %d",a,b);
}

//By Using Xor Operator
#include <stdio.h>
int swap(int ,int );
int main()
{
    int a,b;
    printf("Enter two numbers to get swaped ");
    scanf("%d%d",&a,&b);
    printf("The two numbers to get swaped are %d %d",a,b);
    a=a^b;
    b=b^a;
    a=a^b;
    printf("\nThe two numbers after swaped are %d %d",a,b);
}

