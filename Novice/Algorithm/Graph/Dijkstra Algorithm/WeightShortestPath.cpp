#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
map<int,list<pair<int,int>>>adjList;
void addEdge(ll u,ll v,ll wt){
    adjList[u].push_back(make_pair(v,wt));
}

void dijsktra(ll src,ll n){
    map<int,int>dist;
    for(ll i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    set<pair<int,int>>s;
    s.insert(make_pair(0,src));
    while(!s.empty()){
        auto p=*(s.begin());
        ll currDis=p.first;
        ll currNod=p.second;
        s.erase(s.begin());
        
        for(auto child:adjList[currNod]){
            if(currDis+child.second<dist[child.first]){
                ll destination=child.first;
                auto f = s.find(make_pair(dist[destination],destination));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[destination]=currDis+child.second;
                s.insert(make_pair(dist[destination],destination));
            }
        }
    }
    for(auto d:dist){
            cout<<d.second<<" ";
    }
    cout<<endl;
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        addEdge(x,y,z);
    }
    dijsktra(1,n);
}
