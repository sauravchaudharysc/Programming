#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
int min(int x,int y,int z)
{
    return min(x,min(y,z));
}
int minCost(int cost[R][C],int m,int n)
{
    int dp[R][C];
    memset(dp,0,sizeof(dp));
    dp[0][0] = cost[0][0]; 
     /* Initialize first column of total cost(dp) array */
     for (int i = 1; i <= m; i++) 
        dp[i][0] = dp[i-1][0] + cost[i][0]; 
  
     /* Initialize first row of dp array */
     for (int j = 1; j <= n; j++) 
        dp[0][j] = dp[0][j-1] + cost[0][j];
        
     for(int i=1;i<R;i++)
     {
         for(int j=1;j<C;j++)
         {
             dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+cost[i][j];
         }
     }
     return dp[m][n];
}
int main()
{
    int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   cout<<minCost(cost, 2, 2);
}