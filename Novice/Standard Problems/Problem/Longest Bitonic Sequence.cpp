#include<bits/stdc++.h>
using namespace std;
int longestBitonicArray(int arr[],int n)
{
    int iS[n];
    for(int i=0;i<n;i++){
        iS[i]=1;
    }
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            iS[i]=iS[i-1]+1;
        }
    }
    int dS[n];
    for(int i=0;i<n;i++){
        dS[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>=arr[i+1]){
            dS[i]=dS[i+1]+1;
        }
    }
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        maximum=max(maximum,(dS[i]+iS[i]-1));
    }
    return maximum;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    
    cout<<longestBitonicArray(a,n)<<endl;}
}