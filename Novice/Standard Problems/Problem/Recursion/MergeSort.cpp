#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void merger(ll arr[],ll lb,ll ub,ll mid){
    ll temp[ub-lb+1];
    ll i,j,k;
    i=lb,j=mid+1,k=0;
    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=ub){
        temp[k++]=arr[j++];    
    }
    for(ll i=lb;i<=ub;i++){
        arr[i]=temp[i-lb];
    }
    
}

void mergeSort(ll arr[],ll lb,ll ub){
    if(lb<ub){
       ll mid = (lb+ub)/2;
       mergeSort(arr,lb,mid);
       mergeSort(arr,mid+1,ub);
       merger(arr,lb,ub,mid);
    }
    
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *arr=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        mergeSort(arr,0,n-1);
        for(ll i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }    
}