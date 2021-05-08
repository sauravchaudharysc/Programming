#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
//Syntax For Creating a template.
template<typename T>
//A Class for graph
class Graph{
//A Map which maps every vertices to its adjacent vertices
  map<T,list<T>> adjList; //Array of linked list
  public:
    Graph(){
        
    }
    //In bidirectional if vertex 1 is connected to 0. Then 0 is also connected to 1.
    void addEdge(T u,T v,bool bidir){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    //Pass the starting vertex
    int bfs(T src,T dest)
    {
        //Initialise a queue
        queue<T> q;
        //A map is used to mark the visited node
        map<T,int> dist;
        map<T,T> parent;
        for(auto i:adjList){
                 //key     //value
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node = q.front(); //To see the node at the top of queue
            //cout<<node<<" ";
            q.pop();
            //For each loop to push adjacent vertices
            for(int neighbour : adjList[node]){
                //Pushed only if the node distance isn't updated
                if(dist[neighbour]==INT_MAX){
                 q.push(neighbour);
                 //Update the distance
                 dist[neighbour]=dist[node]+1;
                 parent[neighbour]=node;
                }
            }
        }
        return dist[dest];
    }
};

int main()
{
    Graph<int> g;
    int t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;
            int board[n+1]={0};
            int ladder;
            int snake;
            cin>>ladder;
            cin>>snake;
            for(int i=0;i<ladder;i++){
                int x,y;
                cin>>x>>y;
                board[x]=y-x;
            }
            
            for(int i=0;i<snake;i++){
                int x,y;
                cin>>x>>y;
                board[x]=y-x;
            }
        
        //Graph Creation
        for(int u=0;u<=n;u++)
        {
            for(int dice=1;dice<=6;dice++){
                int v=u+dice+board[u+dice];
                g.addEdge(u,v,false);//False because it is unidirectional
            }
        }
        cout<<g.bfs(0,n)<<endl;
    }    
}