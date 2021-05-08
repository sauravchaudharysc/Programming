#include<bits/stdc++.h>
using namespace std;

int getCount(int arr[],int n,int k){
    
    unordered_map<int,int>mp;
    
    int count=0;
    int currsum=0;
    
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        
        if(currsum==k){
            cout<<i<<endl;
            count++;
        }
        else if(mp.find(currsum-k)!=mp.end()){
            cout<<i<<endl;
            count+=mp[currsum-k];
        }
        mp[currsum]++;
    }
    return count;
}

int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getCount(arr,n,0);
}