//BFS 
#include<iostream>
#include<map>
#include<list>
#include<queue>
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
    void addEdge(T u,T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        //Iterate the map
        for(auto obj: adjList){
            cout<<obj.first<<" -> ";
            //obj.second is linked list
            for(auto entry:obj.second){
                cout<<entry<<" ,";
            }
            cout<<endl;
        }
    }
    //Pass the starting vertex
    void bfs(T src)
    {
        //Initialise a queue
        queue<T> q;
        //A map is used to mark the visited node
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            //For each loop to push adjacent vertices
            for(int neighbour : adjList[node]){
                //Pushed only if the node isnt visited
                if(!visited[neighbour]){
                 q.push(neighbour);
                 //Mark the visited node
                 visited[neighbour]=true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g2;
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(0,4);
    g2.addEdge(2,4);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.print();
    g2.bfs(0);
}