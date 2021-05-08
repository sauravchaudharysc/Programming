//Total count of numbers which are divisble by prime numbers less than 20
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll t;
    cin>>t;
    
    ll primes[]={2,3,5,7,11,13,17,19};
    while(t--){
        ll n;
        cin>>n;
        ll subsets=(1<<8)-1;//Similar to 2^8-1 itne because itne combination honge upar die hue number ke
         ll total=0;
        for(ll i=1;i<=subsets;i++){
            ll denominator=1ll;
            ll setBits=__builtin_popcount(i);//inbuilt method to give no of set bits
            for(ll j=0;j<=7;j++){
                if(i&(1<<j)){
                    denominator=denominator*primes[j];
                }
            }
            if(setBits&1){
                total=total+(n/denominator);    
            }else{
                total=total-n/denominator;
            }
        }
        cout<<total<<endl;
    }
}