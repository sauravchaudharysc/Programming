/*There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.

Input Format
First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).

Constraints
1<=n<=10^5 |c|<=10^9 1<=r<=10^9

Output Format
Print a single integer denoting the answer.

Sample Input
4
1 1
2 1
3 1
4 1
Sample Output
2
Explanation
We can remove 1st and 3rd circle, or 2nd and 4th circle.*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return (a.second<b.second);
}
int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>diameter;
    for(int i=0;i<n;i++){
        ll c,r;
        cin>>c>>r;
        ll start=c-r;
        ll end=c+r;
        diameter.push_back(make_pair(start,end));
    }
    sort(diameter.begin(),diameter.end(),compare);
    ll count=1;
    ll curr=diameter[0].second;
    //Non-Overlapping Circles
    for(int i=1;i<n;i++){
        if(diameter[i].first>=curr){
             count++;           
             curr=diameter[i].second;
        }
    }
    //Total - Non-Overlapping gives Overlapping count.
    cout<<n-count<<endl;
}