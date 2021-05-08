//Bottom Up-Approach
//Calculate value of big-problems using smaller sub-problems.
#include<bits/stdc++.h>
using namespace std;
/*Space Complexity O(N)
  Time Complexity O(N)*/
int fib(int n) 
{
    int *dp = new int[n+1];
    dp[n+1] = {0};
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]; //Since,fib(n)=fib(n-1)+fib(n-2);
    }
    return dp[n];
}

//Bottom Up Approach With Space Optimized
/*Space Complexity O(1)
  Time Complexity O(N)*/
 int fibSpaceOptimized(int n) 
{
    if(n==0 || n==1)
    {
        return n;
    }
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c = a + b; //Since,fib(n)=fib(n-1)+fib(n-2);
        a = b;
        b = c;
    }
    return c;
} 
int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    cout<<fibSpaceOptimized(n);
}