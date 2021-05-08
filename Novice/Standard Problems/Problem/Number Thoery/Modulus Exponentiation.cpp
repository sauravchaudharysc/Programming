/*
Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
Explanation
(2^2)mod 3=4 mod 3 = 1


(x*y)%n == ((x%n)*(y%n))%n
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll power(ll a,ll b,ll c){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll x=(power(a,b/2,c)%c);
    if(b&1)
        return (x*a*x)%c;
    else
        return (x*x)%c;
}

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll powerAns=power(a%c,b,c);
    int mod = powerAns%c;
    cout<<mod<<endl;
}