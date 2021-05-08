#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
#define MOD 1000000007
int numWays(int row,int col)
{
    //Base case
    if(dp[0][0]==-1){   /*Starting Cell is blocked*/
        return 0;
    }
    //Compute the no of ways for first row
    for(int j=0;j<col;j++){
        if(dp[0][j]==-1){
            break;
        }
        dp[0][j]= 1;
    }
    //Compute the no of ways for first col
    for(int i=0;i<row;i++){
        if(dp[i][0]==-1)
        {
            break;
        }
        dp[i][0]=1;
    }
    //Rest Of the Matrix
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++)
        {
            //If cell is blocked leave it.Visit next row
            if(dp[i][j]==-1){
                continue;
            }
            //Check for Left Side
            if(dp[i][j-1]!=-1){
                dp[i][j]=dp[i][j-1]%MOD;
            }
            //Check for Top 
            if(dp[i-1][j]!=-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;    
            }
        }
    }
    if(dp[row-1][col-1]==-1){
        return 0;
    }
    return dp[row-1][col-1];
}
int main()
{
    memset(dp,0,sizeof(dp));
    int M,N,P;
    cin>>M>>N>>P;
    for(int i=0;i<P;i++)
    {
        int X,Y;
        cin>>X>>Y;
        dp[X-1][Y-1]=-1;
    }
    cout<<numWays(M,N);
}