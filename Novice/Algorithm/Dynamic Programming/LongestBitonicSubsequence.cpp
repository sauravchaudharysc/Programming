/*A Longest Bitonic Subsequence is the Subsequence which is first increasing and then
decreasing.*/
/*So here we calculate first the increasing Subsequence and then the decreasing Subsequence can
be calculated from the increasing Subsequence from last.So We now just add both the
LIS and DIS value and observe the maximum value and subtract it by 1 since the same 
element is considered twice . The maximum value obtained is the answer*/
#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(int arr[])
{
    int n = 8;
    int iS[n];
    for(int i=0;i<n;i++){
        iS[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                int curr=1+iS[j];
                iS[i]=max(curr,iS[i]);
            }
        }
    }
    int dS[n];
    for(int i=0;i<n;i++){
        dS[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                int curr=1+dS[j];
                dS[i]=max(curr,dS[i]);
            }
        }
    }
    int ans=dS[0]+iS[0]-1;
    for(int i=1;i<n;i++){
        ans=max(ans,dS[i]+iS[i]-1);
    }
    return ans;
}

int main()
{
    int arr[] = {1,11,2,10,4,5,2,1}; 
    cout<<longestBitonicSubsequence(arr);
}