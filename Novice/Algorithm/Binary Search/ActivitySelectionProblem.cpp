//Activity Selection Problem
//Sort according to end time so we can do alot of jobs
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main()
{
    int t;
    cin>>t;
    vector<pair<int,int>>v;
    while(t--){
        int n,s,e;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        //Activity Selection ALgorithm
        //Sorting on the basis of end time
        sort(v.begin(),v.end(),compare);
        //Start Picking Activities
        int res=1;
        int finish=v[0].second;
        for(int i=2;i<n;i++){
            if(v[i].first>=finish){
                finish=v[i].second;
                res++;
            }
        }
        cout<<res<<endl;
        //to clear the vector for each test cases
        v.clear();
    }
}