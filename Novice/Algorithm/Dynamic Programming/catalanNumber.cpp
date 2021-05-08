#include<bits/stdc++.h>
using namespace std;
//Bottom Up Approach
int noOfBst(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=0;
        for(int k=1;k<=i;k++){
           dp[i]+=dp[k-1]*dp[i-k];
        }
    }
    return dp[n];
}
//Top Down Approach
int uniqueBSTs(int n) 
{ 
    int n1, n2, sum = 0; 
    if (n == 1 || n == 0) 
        return 1; 
    for (int i = 1; i <= n; i++) { 
        n1 = uniqueBSTs(i - 1); 
        n2 = uniqueBSTs(n - i); 
        sum += n1 * n2; 
    } 
    return sum; 
} 
int  main()
{
    int n;
    cin>>n;
    cout<<noOfBst(n)<<endl;
    cout<<uniqueBSTs(n);
}