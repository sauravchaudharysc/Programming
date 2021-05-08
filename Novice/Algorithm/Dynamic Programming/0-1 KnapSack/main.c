/*Dynamic Programming involves sequence of steps.We try all possible solution and choose the best one.In 0/1 knapSack we need to keep the object the bag in such a way tha profit is maximized.In this we cant take fraction of objects.We need to carry the object if total object can be adjusted or we willn't take it.So total solution will be 2^n. So here dynamic programming helps us to reduce the time-complexity. */
#include<stdio.h>
// A utility function that returns 
// maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int knapSack(int val[],int wt[],int W,int n){
    //Make an 2-d dp array of no of items and weights
    int dp[n+1][W+1];
    
    //Fill the dp array in bottom wise manner
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            //The first row belongs to zero item included so mark them zero.
            //The second row belongs to zero weight included so mark them zero.
            if(i==0 || w==0){
                dp[i][w]=0;
            }else if(wt[i-1]<=w){
                /*Two cases:- 
                Check the two cases and choose the max value.
                1. Do not include the current object and check it value.
                2. Include the current object and then subtract the weight
                   of included object.Find the value of the weight remaning
                   and check its value in dp.Sum both of the value.*/
                dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    printf("The maximum profit is %d\n",dp[n][W]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    //To Know which object are included
    //Start i from n and j from W.These index contain the maximum profit
    int i=n;
    int j=W;
    while(i>0 and j >0){
        if(dp[i][j]==dp[i-1][j]){
            printf("%d - 0 \n",i);
            i--;
        }else{
            printf("%d - 1 \n",i);
            //We decrement the i value first because this helps us to access
            //wt array correctly because it follow 0 base indexing
            i--;
            j = j-wt[i];
        }
    }    
}
int main()
{
    int val[] = { 1,2,5,6 }; 
    int wt[] = { 2,3,4,5 }; 
    int W = 8; 
    int n = sizeof(val) / sizeof(val[0]); 
    
    // int val[] = { 60, 100, 120 }; 
    // int wt[] = { 10, 20, 30 }; 
    // int W = 50; 
    // int n = sizeof(val) / sizeof(val[0]); 
    knapSack(val,wt,W,n);
}