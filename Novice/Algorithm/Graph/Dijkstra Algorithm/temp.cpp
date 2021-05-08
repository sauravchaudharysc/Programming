#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
class Graph{
    public:
      int v;
      //Array of pair of list
      //Index of array defines a vertex and pair defines destination vertex and weight
      list<pair<int,int>>*adj;
      
      Graph(int v){
          this->v=v;
          adj=new list<pair<int,int>>[v];
      }
      void addEdge(int u,int v,int w){
          adj[u].push_back(make_pair(v,w));
          adj[v].push_back(make_pair(u,w));
      }
      int findMinVertex(int *weight,bool *visited,int v){
          int minVertex = -1;
          for(int i=0;i<v;i++){
              if(!visited[i] and (minVertex == -1 or weight[i]<weight[minVertex])){
                  minVertex=i;
              }
          }
          return minVertex;
      }
      void Prims(){
          bool *visited = new bool[v];
          int *parent = new int[v];
          int *weight = new int [v];
          for(int i=0;i<v;i++){
              visited[i] = false;
              weight[i] = inf;
          }
          parent[0]=-1;
          weight[0]=0;
         for(int i=0;i<v;i++){
              int minVertex=findMinVertex(weight,visited,v);
              visited[minVertex]=true;
          
            for(auto neighbour:adj[minVertex]){
              if(!visited[neighbour.first]){
                  if(weight[neighbour.first]>(neighbour.second + weight[minVertex]))//Comparing weights
                  {
                      parent[neighbour.first]=minVertex;
                      weight[neighbour.first]=(neighbour.second + weight[minVertex]);
                  }
              }
            }
          }  
          for(int i=0;i<v;i++){
              cout<<weight[i]<<" ";
          }
          cout<<endl;
      }
};


int main()
{
    int n,e;
    cin>>n>>e;
    Graph g(n);
    int u,v,w;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }    
    g.Prims();
}