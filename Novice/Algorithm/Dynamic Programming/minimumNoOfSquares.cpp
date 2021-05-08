/*Number of Perfect Square Required to Sum up till given n*/

#include<bits/stdc++.h>
using namespace std;
int perfectSquare(int n,int dp[]){
    if(n==0){
        return 0;
    }
        
    if(dp[n]!=-1){
        return dp[n];
    }
        
    int minValue = INT_MAX;
        
    for(int i=1;i*i<=n;i++){
        int abhiTakKaAnswer = perfectSquare(n - i*i,dp) + 1;
        minValue = min(minValue,abhiTakKaAnswer);
    }
    dp[n] = minValue;
    return minValue;
}
int main()
{
    int dp[100];
    memset(dp,-1,sizeof(dp));
    cout<<perfectSquare(16,dp);
}