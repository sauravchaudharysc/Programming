#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
class Graph{
    public:
      int v;
      //Vector of Vector
      //Index of array defines a vertex and pair defines destination vertex and weight
      vector<vector<pair<int,int>>>adj;
      
      Graph(int v){
          this->v=v;
          adj.resize(v+1); // For 1 base indexing v+1
      }
      
      void addEdge(int u,int v,int w){
          adj[u].push_back(make_pair(v,w));
          adj[v].push_back(make_pair(u,w));
      }
      /*This give the vertex which hasn't been visited but can be visited only from
      the visited node.*/
      int findMinVertex(int *weight,bool *visited,int v){
          int minVertex = -1;
          for(int i=1;i<=v;i++){
              if(!visited[i] and (minVertex == -1 or weight[i]<weight[minVertex])){
                  minVertex=i;
              }
          }
          return minVertex;
      }
      void Prims(){
          bool *visited = new bool[v+1];
          int *parent = new int[v+1];
          int *weight = new int [v+1];
          for(int i=0;i<=v;i++){
              visited[i] = false;
              weight[i] = inf;
          }
          //Parent and Weight Node for Arbitrary Node
          parent[1]=-1;
          weight[1]=0;
          
         for(int i=1;i<=v;i++){
              //Find the node which is not visited,distance is minimum
              int minVertex=findMinVertex(weight,visited,v);
              visited[minVertex]=true;
          
            for(auto neighbour:adj[minVertex]){
             /* I will explore the child from current vertex. If i get visited vertex
             that is already part of my tree . So i shouldnt choose it.*/   
              if(!visited[neighbour.first]){
                  /*A node can reach through multiple nodes. So we update it so that
                  we can reach it through minimum edge weight.*/
                  if(weight[neighbour.first]>neighbour.second)//Comparing weights
                  {
                      //Update the parent of the child
                      parent[neighbour.first]=minVertex;
                      //Update the weight
                      weight[neighbour.first]=neighbour.second;
                  }
              }
            }
          }
          
          for(int i=1;i<=v;i++){
              cout<<i<<" --"<<parent[i]<<" with weight "<<weight[i]<<endl;
          }
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
        g.addEdge(u,v,w);
    }    
    g.Prims();
}