
//DFS
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
    void dfsHelper(T node,map<T,bool>&visited){
        //Whenever you come to a node mark is visited
        visited[node] = true;
        cout<<node<<" ";
        //Try to find out if neighbour is visited or not
        //If not visited then visit it.
        for(T neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        dfsHelper(src,visited);
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
    g2.dfs(0);
    
}