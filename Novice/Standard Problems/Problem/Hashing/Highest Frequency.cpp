/*Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.

Input Format
Enter the size of the array N and add N more numbers and store in an array

Constraints
1 <= N <= 10^7

Output Format
Display the number with the maximum frequency.

Sample Input
5
1 2 2 2 3
Sample Output
2
Explanation
2 has the highest frequency in the array i.e. 3.*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,x;
    cin>>n;
    unordered_map<int,int>hash;
    for(ll i=0;i<n;i++){
        cin>>x;
        hash[x]++;
    }
    ll ans=0;
    ll freq=INT_MIN;
    for(auto i=hash.begin();i!=hash.end();i++){
        if(i->second>freq){
            freq=i->second;
            ans=i->first;
        }
    }
    cout<<ans<<endl;
}