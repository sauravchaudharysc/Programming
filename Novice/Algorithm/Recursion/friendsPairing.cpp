#include<bits/stdc++.h>
using namespace std;
int friendPairing(int n)
{
    if(n==1 || n==2)
    {
        return n;
    }
    int stag=friendPairing(n-1);
    int pair=friendPairing(n-2);
    return stag+pair*(n-1);
}
int  main()
{
    int n;
    cin>>n;
    cout<<friendPairing(n);
}