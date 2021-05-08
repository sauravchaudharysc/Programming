#include<bits/stdc++.h>
using namespace std;
int countBoardPath(int start,int end)
{
    if(start==end)
    {
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    int count=0;
    for(int dice=1;dice<=6;dice++)
    {
        count+=countBoardPath(start+dice,end);
    }
    return count;
}
int countBoardPathDpTD(int start,int end,int dp[])
{
    if(start==end)
    {
        dp[start] = 1;
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    
    if(dp[start]!=0){
		return dp[start];
	}
	
    int count=0;
    for(int dice=1;dice<=6;dice++)
    {
        count+=countBoardPathDpTD(start+dice,end,dp);
    }
    dp[start]=count;
    return count;
}
/*In Count Board Path the way to obtain 1 is 1. TO obtain
2 is 2. And to obtain 3 is 3. A pattern of sum is obtaine
so we can make this a formula*/
int countBoardPathBu(int start,int end)
{
    int dp[end-start+1];
    dp[0]=1;
    for(int i=1;i<=end;i++)
    {
        dp[i]=0;
        for(int j=1;j<=i;j++)
        {
            dp[i]+=dp[j-1];
        }
    }
    return dp[end];
}
/*Here in ladder we only use last 3 value to get 4th value
.So we can know the 5th value by 
a[last](all the three values)+a[last]-a[last-k]*/
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
    cout<<countBoardPath(0,6)<<endl;
    int dp[7]={0};
    cout<<countBoardPathDpTD(0,6,dp)<<endl;
    cout<<countBoardPathBu(0,6)<<endl;
    cout<<ladder_Optimized(6,3);
} 