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
    bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &instack)
    {
        visited[node]=true;
        instack[node]=true;
        //Explore the neighbours
        for(T neighbours:adjList[node]){
            //Two things can happens
            //If current node is not visited but its further branch lead to a cycle.
            if((!visited[neighbours] && isCyclicHelper(neighbours,visited,instack ))||instack[neighbours]){
                return true;
            }
        }
        //Pop out removes an element from stack
        instack[node]=false;
        return false;
        
    }
    //Pass the starting vertex
    bool isCyclicDFS()
    {
        //A map is used to mark the visited node
        map<T,bool> visited;
        //A map to keep a track o\f stack
        map<T,bool>instack;
        //For each loop to push adjacent vertices of node
        for(auto i : adjList){
         T node = i.first;
         if(!visited[node]){
             bool cyclePresent= isCyclicHelper(node,visited,instack);
            if(cyclePresent){
                return true;
            }
             
         }
        }
        return false;
    }
};

int main()
{
    Graph<int> g2;
    g2.addEdge(0,2,false);
    g2.addEdge(0,1,false);
    g2.addEdge(2,4,false);
    g2.addEdge(2,3,false);
    g2.addEdge(3,0,false);
    g2.addEdge(1,5,false);
    g2.addEdge(4,5,false);
    g2.print();
    if(g2.isCyclicDFS()){
        cout<<"yes cycle found";
    }else{
        cout<<"No ";
    }
}