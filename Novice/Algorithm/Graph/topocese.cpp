#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<ll,list<ll>>adjList;

void addEdge(int u,int v){
    adjList[u].push_back(v);
}

bool isCyclic(int src, map<ll,bool>&visited,map<ll,bool>&instack){
    visited[src]=true;
    instack[src]=true;
    for(auto obj:adjList[src]){
        if((!visited[obj] && isCyclic(obj,visited,instack))||instack[obj]){
            return true;
        }
    }
    instack[src]=false;
    return false;
}



bool dfs(){
    map<ll,bool>visited;
    map<ll,bool>instack;
    for(auto obj:adjList){
        ll vertex=obj.first;
        if(visited[vertex]==0){
            bool isCycle=isCyclic(vertex,visited,instack);
            if(isCycle){
                return true;
            }
        }
    }
    return false;
}

void dfsUtil(ll src,map<ll,bool>&visited,stack<ll>&s){
    visited[src]=true;
    for(auto obj:adjList[src]){
        if(visited[obj]==0){
            dfsUtil(obj,visited,s);
        }
    }
    s.push(src);
}

void dfsTopo(){
    map<ll,bool>visited;
    stack<ll>s;
    for(auto obj:adjList){
        ll vertex=obj.first;
        if(visited[vertex]==0){
            dfsUtil(vertex,visited,s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    if(dfs()){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        dfsTopo();
    }
}