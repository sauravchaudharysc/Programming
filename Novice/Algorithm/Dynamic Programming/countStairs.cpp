#include<bits/stdc++.h>
using namespace std;
int countStair(int n,int k,int dp[])
{
    //Base case
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    //recursive case
    int ways=0;
    for(int i=1;i<=k;i++) {
        if(n-i>=0){
            ways+=countStair(n-i,k,dp);
        }
    }
    return dp[n]=ways;
}
int countStair_BottomUp(int n,int k)
{
    int dp[100]={0};
    dp[0] =1;
    for(int i=1;i<=n;i++){
        dp[i] =0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
             dp[i]+=dp[i-j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}
//Sliding window
//dp[i+1]=dp[i]+dp[i-k].put i=i-1;
int countStair_BottomUpOptimized(int n,int k)
{
    int dp[100]={0};
    dp[0] =dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}
int main()
{
   int n,k;
   cin>>n>>k;
   int dp[n+1]={0};
   //cout<<countStair(n,k,dp);
     cout<<countStair_BottomUp(n,k)<<endl;
     cout<<countStair_BottomUpOptimized(n,k)<<endl;   
}