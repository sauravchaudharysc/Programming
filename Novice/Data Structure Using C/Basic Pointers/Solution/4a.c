// :) :)
//Factorial
#include <stdio.h>
int fact(int);
int main()
{
    int n;
    printf("Enter the number to get it factorial");
    scanf("%d",&n);
    printf("The factorial of %d is %d",n,fact(n));
}
int fact(int a)
{
    if(a==0)
    return 1;
    return(a*fact(a-1));
}

