// :) :)
#include<stdio.h>
int main()
{
int a,b;
printf("Enter two number to get it GCD or HCF");
scanf("%d%d",&a,&b);
printf("The gcd is %d",gcd(a,b));
}
gcd(int a,int b)
{
if(b==0)
return a;
return gcd(a,a%b);
}

