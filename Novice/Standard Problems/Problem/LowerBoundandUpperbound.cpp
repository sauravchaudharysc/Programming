#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        auto it1 = lower_bound(arr,arr+n,x);
        auto it2 = upper_bound(arr,arr+n,x);
        if(arr[it1-arr]!=x){
            cout<<"-1"<<" "<<"-1"<<endl;           
        }else{
            cout<<(it1-arr)<<" "<<(it2-arr-1)<<endl;
        }
    }
}