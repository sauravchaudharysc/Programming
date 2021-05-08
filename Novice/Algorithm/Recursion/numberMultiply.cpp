#include<bits/stdc++.h>
using namespace std;
int numberMultiply(int n,int p)
{
    if(p==0)     
    {
    return 0;
    }
    int result=numberMultiply(n,p-1);
    return (n+result);
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<numberMultiply(n,p);
    
}