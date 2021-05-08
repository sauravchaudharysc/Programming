#include<bits/stdc++.h>
using namespace std;

map<int,list<pair<int,int>>>adjList;

void addEdge(int u,int v,int w){
    adjList[u].push_back(make_pair(w,v));
    adjList[v].push_back(make_pair(w,u));
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjList[a].push_back(make_pair(c,b));
        adjList[b].push_back(make_pair(c,a));
    }
    int B;
    cin>>B;
    vector<int>v;
    vector<int>dist(n+1,INT_MAX);
    while(B--){
     int a;
     cin>>a;
     v.push_back(a);
     dist[a]=0;
    }
    for(int i=0;i<v.size();i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,v[i]});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int x=p.first;
            int xx=p.second;
            for(auto obj:adjList[xx]){
               
                if(obj.first+x<dist[obj.second]){
                    dist[obj.second]=obj.first+x;
                    pq.push({dist[obj.second],obj.second});
                }
            }
        }
    }
for(int i=1;i<=n;i++)
cout<<dist[i]<<endl;
    
}