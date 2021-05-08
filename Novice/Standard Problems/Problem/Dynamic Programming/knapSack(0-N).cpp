//0-N knapSack
//There is a slight change from 0-1 knapSack to 0-N knapSack.
/*
In 0-1 if the element is considered once or discarded once it cant be considered again.
But in case of 0-N , in case of discarded it is same but in case of consideration there 
is a slight change. We can consider the element again and again. 

So we modify the code a slight in else if part.We dont exclude the object by doing i-1.
We keep it i.
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int Wt,int wt[],int val[],int n){

    int dp[n+1][Wt+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=Wt;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }else if(wt[i-1]<=w){
                dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i][w-wt[i-1]]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][Wt];
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