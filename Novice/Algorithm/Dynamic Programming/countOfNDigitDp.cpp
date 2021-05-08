#include<bits/stdc++.h>
using namespace std;
unsigned long long int dp[101][501];
unsigned long long int countRec(int n,int sum)
{
    if(n==0){
        return sum==0;
    }
    if(sum==0){
        return 1;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    unsigned long long int ans=0;
    for(int i=0;i<=9;i++){
        if(sum-i>=0){
            ans+=countRec(n-1,sum-i);
        }
    }
    return dp[n][sum]=ans;
}
int sumOfDigits(int n,int sum)
{
    memset(dp,-1,sizeof(dp));
    if(n==0)
    {
        return 0;
    }
    unsigned long long int ans=0;
    for(int i=1;i<=9;i++)
    {
        if(sum-i>=0)
        {
            ans+=countRec(n-1,sum-i);
        }
    }
    return ans;
}
int main()
{
    cout<<sumOfDigits(3,5);
}