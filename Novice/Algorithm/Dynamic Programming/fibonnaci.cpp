//Top Down Approach
//Recursion and Memoisation of optimal sub problems in dp[] array.
#include<bits/stdc++.h>
using namespace std;
int fib(int n,int dp[])
{
    if(n==0 || n==1) //base case
    {
        dp[n]=n;
        return dp[n];
    }
    if(dp[n]!=0)   //check for value of dp if it isn't zero .
    {
        return dp[n]; //return the value
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int *dp=new int[n+1];
    dp[n]={0};
    cout<<fib(n,dp);
}