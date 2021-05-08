#include<bits/stdc++.h>
using namespace std;

int getCount(int arr[],int n,int k){
    
    unordered_map<int,vector<int>>mp;
    
    // create an empty vector of pairs to store 
    // subarray starting and ending index 
    vector <pair<int, int>> out; 
    
    
    int count=0;
    int currsum=0;
    
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        
        if(currsum==k){
            out.push_back(make_pair(0, i));
        }
        else if(mp.find(currsum-k)!=mp.end()){
             vector<int> vc = mp[currsum-k]; 
            for (auto it = vc.begin(); it != vc.end(); it++) 
                out.push_back(make_pair(*it + 1, i));
        }
        mp[currsum].push_back(i);
    }
    for (auto it = out.begin(); it != out.end(); it++) 
        cout << "Subarray found from Index " << it->first << " to " << it->second << endl;
            
            
    return count;
}

int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getCount(arr,n,0);
}