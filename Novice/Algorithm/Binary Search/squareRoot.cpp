//O(LogN+P)
#include<bits/stdc++.h>
using namespace std;
float square_Root(int n)
{
    int start=0;
    int end=n;
    int p=4;
    float ans=-1;
    while(start<=end){
        int mid=(start+end)>>1;
        if(mid*mid==n){
            return mid;
        }else if(mid*mid<n){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    //Floating part
    //Brute Force
    float inc=0.1;
    for(int times=1 ; times<=p; times++){
        while(ans * ans <=n){
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<square_Root(n)<<endl;
}