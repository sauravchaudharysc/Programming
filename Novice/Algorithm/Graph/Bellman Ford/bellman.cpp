#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,pair<int,int>>>adjList;

void addEdge(int count,int u,int v,int w){
    adjList[count]=make_pair(u,make_pair(v,w));
}

void BellmanFord(int src,int v,int e){
    int dist[v+1];
    for(int i=1;i<=v;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
   
    for(int i=1;i<v;i++){
        for(int j=0;j<e;j++){
            int u=adjList[j].first;
            int v=adjList[j].second.first;
            int w=adjList[j].second.second;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    
    for(int i=2;i<=v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(i,u,v,w);    
    }
    BellmanFord(1,n,m);
    //   for(auto obj:adjList){
    //     cout<<obj.second.first<<" "<<obj.second.second.first<<" "<<obj.second.second.second<<endl;
    //   }  
    
}