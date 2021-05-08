#include<bits/stdc++.h>
using namespace std;
int reduceToOne(int n)
{
    if(n==1)
    {
        return 0;
    }
    int count1,count2,count3;
    count1=count2=count3=INT_MAX;
    if(n%3==0)
    {
        count3=reduceToOne(n/3)+1;
    }
    if(n%2==0)
    {
        count2=reduceToOne(n/2)+1;
    }
    count3=reduceToOne(n-1)+1;
    return min(count1,min(count2,count3));
}
int main()
{
   cout<<reduceToOne(4);
}