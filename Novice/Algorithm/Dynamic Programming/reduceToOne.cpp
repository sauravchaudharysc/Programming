#include<bits/stdc++.h>
using namespace std;
//Top-Down Approach
/*Here we maintain a dp array
and for each subproblem we store
it output*/
int reduceToOne(int n,int dp[])
{
    if(n==1)
    {
        dp[n]=0;
        return dp[n];
    }
    if(dp[n]!=0)  //Checks is the subproblem calculated before
    {
        return dp[n]; //If calculated return the value
    }
    int count1,count2,count3;
    count1=count2=count3=INT_MAX;
    if(n%3==0)
    {
        count3=reduceToOne(n/3,dp)+1;
    }
    if(n%2==0)
    {
        count2=reduceToOne(n/2,dp)+1;
    }
    count1=reduceToOne(n-1,dp)+1;
    dp[n]=min(count1,min(count2,count3)); //Keep a track of output of subproblems.
    return dp[n];
}
//Bottom-Up Approach
/*Start from smaller subproblems
using smaller problems calculate 
large problems output*/
int reduceToOneBu(int n){
    int dp[n+1]={0};
    dp[1]=0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=n;i++)
    {
        int x,y,z;
        x=y=z=INT_MAX;
        if(i%2==0)
        {
            x=dp[i/2]+1;
        }
        if(i%3==0)
        {
            y=dp[i/3]+1;
        }
        z=dp[i-1]+1;
        dp[i]=min(x,min(y,z));
    }
    return dp[n];
}

int main()
{ 
    int n;
    cin>>n;
    int *dp=new int[n+1];
    cout<<reduceToOne(n,dp)<<endl;
    cout<<reduceToOneBu(n);
}