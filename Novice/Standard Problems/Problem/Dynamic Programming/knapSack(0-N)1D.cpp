/*We take each object once for each weight.And calculate the profit.
The dp array containts the maximum weight for each i(weight) considered.

We check and store the maximum weight in dp[i]>

dp[i]=Current store maximum weight
dp[i-wt[j]]+val[j]=Newly obtained maximum weight.*/

#include<bits/stdc++.h>
using namespace std;

int knapSack(int Wt,int wt[],int val[],int n){

    int dp[Wt+1]; 
    memset(dp, 0, sizeof dp); 
  
    for (int i=0; i<=Wt; i++) 
      for (int j=0; j<n; j++) 
         if (wt[j] <= i) 
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]); 
  
    return dp[Wt]; 
}

int main(){
    int n,W;
    cin>>n>>W;
    int wt[n],v[n];
 
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>v[i];
    
	cout << knapSack(W,wt,v,n)<< endl; 

	return 0; 
}