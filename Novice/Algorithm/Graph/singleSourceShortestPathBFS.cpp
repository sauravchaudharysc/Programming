//Application Of BFS
//Single Source Shortest Path
/*
Use a queue and a distance array.
Initialise all the distance to infinity.
Make the distance of starting node a zero.
distance[child]=distance[parent]+1.
So push the source in the queue.And then i pop out this node .
And push the neighbours which arent visited.Neighbours will be at distance 1.
Subsequently neighbours are assigned distance.And you can check if a weight is 
assigned once you dont need to push it.*/
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
        for(auto i:adjList){
            T node=i.first;
            cout<<"Dist of neighbour from "<<src<<" to "<<node<<" is "<<dist[node]<<endl;
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
    g2.bfs(0);
}