//Greedy Approach Workd For Only Indian Currency
//So for other currency we need DP
#include<bits/stdc++.h>
using namespace std;

//Top Down Approach
int minimumCoins(int n,int coins[],int T,int dp[])
{
    //base case
    if(n==0){
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    //recursive case
    int ans=INT_MAX;
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)
        {
            int subprob = minimumCoins(n-coins[i],coins,T,dp);
            ans= min(ans,subprob+1);
        }
    }
    dp[n]=ans;
    return dp[n];
}

//Bottom Up Approach
int minimumCoinsBu(int N,int coins[],int T)
{
    int dp[N+1]={0};
    if(N==0)
    {
        return 0;
    }
    //Iterate over all states 1....N
    for(int n=1;n<=N;n++)
    {
         //Init the current ans as INT_MAX
        dp[n] = INT_MAX;
            for(int i=0;i<T;i++)
            {
                    if(n-coins[i]>=0){
                        int subprob=dp[n-coins[i]];
                        dp[n] = min(dp[n],subprob+1);
                    }
            }
    }
    return dp[N];
}
int main()
{
    int n=15;
    int coins[] ={1,7,10};
    int dp[n+1]={0};
    int T=sizeof(coins)/sizeof(int);
    cout<<minimumCoins(n,coins,T,dp)<<endl;
    cout<<minimumCoinsBu(n,coins,T);
}