#include<bits/stdc++.h>
using namespace std;

//Recursive
int knapSack(int W,int wt[],int val[],int n)
{
    //Base case
    /*No Object is left or the weight is empty.*/
    if(n== 0 || W== 0){
        return 0;
    }
    
    //Checks whether the value to be check is greater than knapSack Weight*/	
    /*Skip the nth item if its weight is greater than knapSack Weight*/
    if(wt[n-1]>W){
        return knapSack(W,wt,val,n-1);
    }
    /*Two cases :- 
     (i)nth item is included so we add the value 
    (ii)nth item is excluded so we skip it.*/
    else{
        return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    }
}

//Top Down Approach
int knapSackTd(int W,int wt[],int val[],int n,int dp[100][100])
{
    //Base case
    /*No Object is left or the weight is empty.*/
    if(n ==0 || W == 0){
        return 0;
    }
    if(dp[n-1][W]!=-1){
        return dp[n-1][W];
    }
    /*Skip the nth item if its weight is greater than knapSack Weight*/
    if(wt[n-1]>W){
        return knapSackTd(W,wt,val,n-1,dp);
    }
    /*Two cases :- 
	(i)nth item is included so we add the value 	
       (ii)nth item is excluded so we skip it.*/
    else{
        dp[n-1][W]=max(val[n-1]+knapSackTd(W-wt[n-1],wt,val,n-1,dp),knapSackTd(W,wt,val,n-1,dp));
    }
    return dp[n-1][W];
}

//Bottom-Up Approach
 int knapSackBu(int W,int wt[],int val[],int n)
{
    int i,w;
    int dp[n+1][W+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            /*Base Case*/
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if(wt[i-1]<=w){
                /*First case:- We need to include the value of that item.And add the solution
                when the item isnt present and decerase the weight of addded value*/
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{   
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<knapSack(W,wt,val,n)<<endl;
    cout<<knapSackTd(W,wt,val,n,dp)<<endl;
    cout<<knapSackBu(W,wt,val,n);
}