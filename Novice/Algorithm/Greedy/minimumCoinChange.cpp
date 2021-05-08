#include<bits/stdc++.h>
int minCoin(int coins[],int amt,int n)
{
    int coinsChange[n];
    int i=0;
    while(amt>0)
    {
        if(amt-coins[n-1]>=0){
            amt=amt-coins[n-1];
            coinsChange[i++]=coins[n-1];
        }else{
            n--;
        }
    }
    for(int j=0;j<i;j++){
       std:: cout<<coinsChange[j]<<" ";
    }
    std:: cout<<"\n";
    return i;
}
int main()
{
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amt;
    std:: cin>>amt;
    std:: cout<<minCoin(coins,amt,n);
}