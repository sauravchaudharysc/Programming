/*You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A, and add it to another array B(initially empty). After these operations, you can rearrange the elements of both the arrays in any order. We define, difference between these two arrays as :

Find the maximum and minimum values of differences of these two arrays.

Input Format
First Line contains number of test cases, T. For each test case, first line contains a single integer, n (n is even). Next line contains n integers, denoting the elements f array, A.

Constraints
1<=T<=10
1<=n<=10^5
|Ai|<=10^9

Output Format
For each test case, print the minimum and maximum value of differences between two arrays.

Sample Input
1
4
12 -3 10 0
Sample Output
5 25*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.push_back(x);    
        }
        sort(v.begin(),v.end());
        ll ans1=0;
        ll ans2=0;
        for(int i=0;i<n;i++){
            if(i&1){
                ans1+=v[i];
            }else{
                ans2+=v[i];
            }
        }
        cout<<abs(ans2-ans1)<<" ";
        ans2=ans1=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans1+=v[i];
            }else{
                ans2+=v[i];
            }
        }
        cout<<abs(ans2-ans1)<<endl;
    }
}