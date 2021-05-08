#include<bits/stdc++.h>
using namespace std;

int findMaxZeroCount(int arr[],int n){
    int zero_Count=0;
    int currZero=0,maxZero=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zero_Count++;
        }
        int val = (arr[i]==1)?1:-1;
        currZero=max(val,currZero+val);
        maxZero=max(currZero,maxZero);
    }
    return zero_Count+maxZero;
}

int main(){
    int arr[]={0, 1, 0, 0, 1, 1, 0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findMaxZeroCount(arr,n);
}