#include<bits/stdc++.h>
using namespace std;
int powerOptimized(int n,int pow)
{
    int ans=1;
    int a=n;
    while(pow>0)
    {
        if(pow&1){
         ans*=a;
        }
        a=a*a;
        pow=pow>>1;
    }
    return ans;
}
int main()
{
    int n;
    int pow;
    cin>>n>>pow;
    cout<<powerOptimized(n,pow);
}