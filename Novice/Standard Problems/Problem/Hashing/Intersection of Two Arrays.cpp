#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    unordered_map<int,int>hash;
    vector<int>ans;
    for(int i=0;i<n;i++){
        cin>>x;
        hash[x]++;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        if(hash[x]){
            ans.push_back(x);
            hash[x]--;   
        }
    }
    sort(ans.begin(),ans.end());
     cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ", ";
    }
    cout << "]"; 
    
}