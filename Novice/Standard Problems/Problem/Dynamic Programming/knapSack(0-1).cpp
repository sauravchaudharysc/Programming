#include<bits/stdc++.h>
using namespace std;

int knapSack(int Wt,int wt[],int val[],int n){

    int dp[n+1][Wt+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=Wt;w++){
            //First row and col are set to be zero.
            //Zero item or zero weight.
            if(i==0||w==0){
                dp[i][w]=0;
            //Weight is <= object weight
            //Two cases :- Take the max among them
            /*
            i.We need to include the value of that item.And add the solution
                when the item isnt present and decerase the weight of addded value
            ii.Check the profit when the current object wasnt included.*/
            }else if(wt[i-1]<=w){
                dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }else{
                //Weight is > object weight
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