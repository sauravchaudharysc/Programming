#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x,i=0;
    cin>>n>>k;
    list<int>l1;
    int m=k;
    auto it=l1.begin();
    while(i<n){
        for(;i<m;i++){
            cin>>x;
            l1.insert(it,x);
            it--;
        }
        advance(it,k);
        if(i+k<n){
            m+=k;
        }else{
            m=n;
        }
    }
    for(auto i :l1){
        cout<<(i)<<" ";
    }
}