#include<bits/stdc++.h>
using namespace std;
int binomialCoefficient(int n,int k)
{
    if(k==0 || k==n){
        return 1;
    }
    else{
      return binomialCoefficient(n-1,k-1)+binomialCoefficient(n-1,k);
    }
}
/*Top-Down Approach*/
int binomialCoefficientTd(int n,int k,int dp[100][100])
{
    if(k==0 || k==n){
        dp[n][k]=1;
        return dp[n][k];
    }
    if(dp[n][k]!=-1){
        return dp[n][k];    
    }
    else{
      dp[n][k]=binomialCoefficientTd(n-1,k-1,dp)+binomialCoefficientTd(n-1,k,dp);
    }
    return dp[n][k];
}
/*Bottom-Up Approach*/
int binomialCoefficientBu(int n,int k)
{
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
           if(j==0 || j==i){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }        
        }
    }
    return dp[n][k];
}
int main()
{
    cout<<binomialCoefficient(5,5)<<endl;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<binomialCoefficientTd(3,2,dp)<<endl;
    cout<<binomialCoefficientBu(3,2)<<endl;
}