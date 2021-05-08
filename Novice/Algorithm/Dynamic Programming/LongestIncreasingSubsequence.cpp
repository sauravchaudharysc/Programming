#include<bits/stdc++.h>
using namespace std;
int LongestIncreasingSubsequence(int n,int arr[])
{
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    int best=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0; j<i ;j++)
        {
            /*Jo Isseh piche ka element h usseh
            chota hona chaiyeh. Then only we can 
            include it in LongestIncreasingSubsequence.*/
            if(arr[j]<arr[i]){
                int currLen= 1 + dp[j]; 
                dp[i]=max(dp[i],currLen);
            }
        }
        /*The Dp array contains the LongestIncreasingSubsequence Count
        So check the maximum value from it array. And that gives you the
        count*/
        best=max(best,dp[i]);
        cout<<best<<" ";
    }
    return best;
}
int main()
{
    int n;
    int arr[n];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<LongestIncreasingSubsequence(n,arr);
    
}