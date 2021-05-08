#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>AdjList;
    public:
        void addEdge(int u,int v,bool bidir){
            AdjList[u].push_back(v);
            if(bidir){
                AdjList[v].push_back(u);
            }
        }
        
        int bfs(int src,int dest){
            queue<int>q;
            map<int,int>dist;
            for(auto i:AdjList){
                dist[i.first]=INT_MAX;
            }
            dist[src]=0;
            q.push(src);
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto neighbour: AdjList[front]){
                    if(dist[neighbour]==INT_MAX){
                        q.push(neighbour);
                        dist[neighbour]=dist[front]+1;
                    }
                }
            }
            return dist[dest];
        }
};


int main(){
  int t;
  cin>>t;
  while(t--){
      Graph g;
      int board[31]={0};
      int n;
      cin>>n;
      for(int i=0;i<n;i++){
          int a;
          int b;
          cin>>a>>b;
          board[a]=b-a;
      }
      for(int u=1;u<=30;u++){
          for(int dice=1;dice<=6;dice++){
             int v=u+dice+board[dice+u];
              g.addEdge(u,v,false);
          }
      }
      cout<<g.bfs(1,30)<<endl;
  }
}