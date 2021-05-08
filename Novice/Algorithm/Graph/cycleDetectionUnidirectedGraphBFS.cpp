//Cycle detection is Unidirected Graph using BFS
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
    bool isCyclicBFS(T src)
    {
        //Initialise a queue
        queue<T> q;
        //A map is used to mark the visited node
        map<T,bool> visited;
        //A map to keep a track of parent node
        map<T,T>parent;
        q.push(src);
        visited[src]=true;
        parent[src]= src;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            //For each loop to push adjacent vertices of node
            for(int neighbour : adjList[node]){
                //If neighbour node is visited and not the parent
                if(visited[neighbour]==true && parent[node]!=neighbour){
                 return true;
                }else if(!visited[neighbour]){
                //push the neighbour in queue
                 q.push(neighbour);
                 parent[neighbour]=node;
                 //Mark the visited node
                 visited[neighbour]=true;
                }
            }
        }
        return false;
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
    g2.addEdge(3,5);
    g2.print();
    if(g2.isCyclicBFS(0)){
        cout<<"yes cycle found";
    }else{
        cout<<"No ";
    }
}