#include<bits/stdc++.h>
using namespace std;
int coinChange(int coins[],int T,int n)
{
  int dp[T+1][n+1]={0};
  for(int i=0;i<=T;i++){
      dp[i][0]=1;
  }
  for(int i=1;i<=n;i++){
      if(i%coins[0]==0){
          dp[0][i]=1;
        }  
  }
  for(int i=1;i<=T;i++){
      for(int j=1;j<=n;j++){
          if(coins[i]>j){
              dp[i][j]=dp[i-1][j];
          }else{
              dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
          }
      }
  }
  return dp[T][n];
}
int main()
{
    int coins[]={1,2,3};
    cout<<coinChange(coins,2,4);
}
