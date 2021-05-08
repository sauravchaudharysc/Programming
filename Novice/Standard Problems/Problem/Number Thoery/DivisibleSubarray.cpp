//Divisible SubArray
//If we want to check for k divisble take a variable k and replace %n by k
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
 int main()
 {
    ll t;
    cin>>t;
    
    while(t--){
        ll n,sum=0,a;
        cin >> n;
            
        ll pre[n+1]={0};
        pre[0]=1;
     
        for(ll i=0;i<n;i++){
           cin>>a;
           sum=(sum+a);
      //It is done two time for larger negative values to turn it to be //positive  
           sum%=n;
           sum=(sum+n)%n;
           pre[sum]++;
        }
        ll x=0;
        for(ll i=0;i<=n;i++){
            x+=pre[i]*(pre[i]-1)/2;
        }
                cout<<x;
    }
    
 }