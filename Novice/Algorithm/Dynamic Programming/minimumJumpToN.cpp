#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int minJumpToReachEnd(int arr[],int n)
{
    int result[n];
    result[0]=0;
    for(int i=1;i<n;i++){
        result[i]=INF;   
    }
    int path[n];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]+j>=i){
                if(result[i]>=result[j]+1){
                    result[i]=result[j]+1;
                    path[i]=j;
                }
            }
        }
    }
    return result[n-1];
}
int main()
{
 int arr[]={1, 3, 6, 1, 0, 9};
 int n=sizeof(arr)/sizeof(arr[0]);
 cout<<minJumpToReachEnd(arr,n);
}