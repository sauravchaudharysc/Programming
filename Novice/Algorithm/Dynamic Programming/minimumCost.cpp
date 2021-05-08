/*A user gives a number and you need to reach it by 
performing doubling,increment by 1 or decrement by 1.
Get the minimum cost to do so.*/
#include<bits/stdc++.h>
using namespace std;
int X,Y,Z;
int minimumCost(int N)
{
    int dp[N+10];
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=N;i++)
    {
        if(N&1==0){
            dp[i]=min(dp[i/2]+X,dp[i-1]+Y);
        }
        else{
            dp[i]=min(dp[i-1]+Y,dp[(i+1)/2]+X+Z);
        }
    }
    return dp[N];
}
int main()
{
    int N;
    cin>>N;
    cin>>X>>Y>>Z;
    cout<<minimumCost(N)<<endl;
}