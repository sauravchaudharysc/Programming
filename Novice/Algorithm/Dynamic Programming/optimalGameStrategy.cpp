#include<bits/stdc++.h>
using namespace std;
int optimal(int a[],int i,int j,int dp[100][100])
{
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans1=a[i]+min(optimal(a,i+1,j-1,dp),optimal(a,i+2,j,dp));
    int ans2=a[j]+min(optimal(a,i+1,j-1,dp),optimal(a,i,j-2,dp));
    dp[i][j]=max(ans1,ans2);
    return dp[i][j];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<optimal(a,0,n-1,dp);
}