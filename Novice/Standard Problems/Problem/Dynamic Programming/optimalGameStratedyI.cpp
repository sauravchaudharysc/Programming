/*Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.*/

#include<bits/stdc++.h>
using namespace std;
int dp[31][31];

int optimalGameStrategyI(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int ans1=arr[i]+min(optimalGameStrategyI(arr,i+1,j-1),optimalGameStrategyI(arr,i+2,j));
    int ans2=arr[j]+min(optimalGameStrategyI(arr,i+1,j-1),optimalGameStrategyI(arr,i,j-2));
    dp[i][j]=max(ans1,ans2);
    return dp[i][j];
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<31;i++){
            for(int j=0;j<31;j++){
                dp[i][j]=-1;
            }
        }
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<optimalGameStrategyI(arr,0,n-1);
    }
    
}