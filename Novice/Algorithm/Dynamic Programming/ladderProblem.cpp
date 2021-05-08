#include<bits/stdc++.h>
using namespace std;
int ladders_topdown(int n,int k,int dp[])
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ways=0;
    for(int i=1;i<=k;i++) 
    {
        if(n-i>=0){
            ways+= ladders_topdown(n-i,k,dp);
        }
    }
    return dp[n] = ways;
}
//For Bottom up we can consider it as sliding windows. And even we observe a pattern
int ladders_bottomup(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j]; //To sum up till K state back
            }
        }
    }
    return dp[n];
}
/*For k=3,To get dp[6] we sum dp[3]+dp[4]+dp[5].
So to get dp[7] we sum 2*dp[6]-dp[3]*/
int ladder_Optimized(int n,int k){
    int dp[100];
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++) //For count board path we only use this 
    {
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1]; //here k=no of steps allowed 1,2,3
    }
    return dp[n];
}
int main()
{
    int n,k;
    //int dp[100]={0};
    cin>>n>>k;
    //cout<<"ways "<<ladders_topdown(n,k,dp)<<endl;
    cout<<ladders_bottomup(n,k);
    
}