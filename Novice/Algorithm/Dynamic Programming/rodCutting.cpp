#include<bits/stdc++.h>
using namespace std;
int rodCutting(int price[],int totalLength)
{
    if(totalLength==0)
    {
        return 0;
    }
    int best=0;
    /*First i will apply a cut of length 1 and recursively call for rest of the 
    length.And this is iterative so it will compute for all cuts.And we will compare
    the profit of each cuts and then update the best.*/
    for(int length=1; length<=totalLength;length++)
    {
        int netProfit=price[length]+rodCutting(price,totalLength-length); 
        best=max(best,netProfit);
    }
    return best;
}
/*To fill a single box of dp array complexity is n.
So to fill all boxes its n*n*/
int rodCuttingDpTD(int price[],int totalLength,int dp[])
{
    if(totalLength==0)
    {
        return 0;
    }
    if(dp[totalLength]!=0)
    {
        return dp[totalLength];
    }
    int best=0;
    for(int length=1; length<=totalLength;length++)
    {
        int netProfit=price[length]+rodCuttingDpTD(price,totalLength-length,dp); 
        best=max(best,netProfit);
    }
    dp[totalLength]=best;
    return best;
}
//Bottom Up Approach
/*First i will calculate for length 1 then subsequent length 
will be calculated*/
int rodCuttingDpBu(int profit[],int totalLength)
{
    int dp[totalLength+1]={0};
    for(int currlen=1;currlen<=totalLength;currlen++) 
    {
        int best=0;
        /*The second for loop calculate the max profit is given by which cut
	 for a particular length */
        for(int cut=1;cut<=currlen;cut++){
            best=max(best,profit[cut]+dp[totalLength-cut]); 
        }
        /*1 Length ke lie max profit kitna h phir uske baad 2 ke lie and go on*/
        dp[currlen]=best;
    }
    return dp[totalLength];  
}
int main()
{
    int priceOfEachLen[100];
    int totalLength;
    cin>>totalLength;
    int dp[totalLength+1]={0};
    for(int eachPiece=1;eachPiece<=totalLength;eachPiece++)
    {
        cin>>priceOfEachLen[eachPiece];
    }
    int ans1=rodCutting(priceOfEachLen,totalLength);
    int ans2=rodCuttingDpTD(priceOfEachLen,totalLength,dp);
    int ans3=rodCuttingDpBu(priceOfEachLen,totalLength);
    cout<<ans1<<" "<<ans2<<" "<<ans3;
}