#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int subsetsum(int arr[],int i,int sum,int ans,int n){
    if(sum==ans){
        return dp[n][sum]=true;
    }
    if(sum>ans || i==n){
        return dp[n][sum]=false;
    }
    if(dp[i][sum]!=-1){
        return dp[i][ans];
    }
    
    int include=subsetsum(arr,i+1,sum+arr[i],ans,n);
    int exclude=subsetsum(arr,i+1,sum,ans,n);
    dp[n][sum] = include || exclude;
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    int ans;
    cin>>ans;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=ans;j++){
            dp[i][j]=-1;
        }
    }
    if(subsetsum(arr,0,0,ans,n)){
        std::cout << "Yes" << std::endl;
    }else{
        cout<<"No"<<endl;
    }
}