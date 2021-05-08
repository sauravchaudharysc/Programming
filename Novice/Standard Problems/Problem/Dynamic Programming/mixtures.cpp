#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[100];
ll dp[100][100];

ll csum(int s,int e){
    ll ans=0;
    for(int i=s;i<=e;i++){
        ans+=arr[i];
        ans%=100;
    }
    return ans;
}
ll solveMixtures(int i,int j){
    if(i>=j){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //We break our expression at every possible k 
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],(solveMixtures(i,k)+solveMixtures(k+1,j)+csum(i,k)*csum(k+1,j)));
    }
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solveMixtures(0,n-1)<<endl;
}