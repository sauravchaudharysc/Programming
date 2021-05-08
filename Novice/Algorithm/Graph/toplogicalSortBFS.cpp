/*
## Topological Sort Using BFS - KAHN'S ALgorithm
    
    -Uses a modified BFS
    -A queue and array/map for storing indegree of each vertex is used 
    -Algorithm starts from finding vertices with 0 indegree
  
<br>
![](topobfs.png)

Steps:<br>
- I push all the vertices in queue with 0 indegree.<br>
- Then i pop out a node from queue.<br>
- So the adjacent vertices of the node degree will decrease by 1.<br>
- So i push the node whose indegree turns out to be zero and repeat until queue 
  becomes empty.
*/
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
    void topologicalSort(){
        queue<T> q;
        map<T,bool>visited;
        map<T,int>indegree;
        
        //Assigning key i.e vertex no to each visited and indegree maps
        for(auto i:adjList){
            //i is pair of node and its list
            T node = i.first;
            visited[node]= false;
            indegree[node]= 0;
        }
        //Initialise the degree of all nodes
        //It is directed graph so if there is edge from u to v 
        //We initalise the degree + 1 
        for(auto i:adjList){
            T u = i.first;
            for(T v: adjList[u]){
                indegree[v]++; //increment at a particular index in map is done this way
            }
        }
        //Find out all the nodes with 0 indegree
        for(auto i:adjList){
            T node = i.first;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        
        //Start with ALgorithm
        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node<<" -->";
            for(T neighbour: adjList[node]){
               indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        
    }
};

int main()
{
    Graph<string> g2;
    g2.addEdge("English","Programming Logic",false);
    g2.addEdge("Maths","Programming Logic",false);
    g2.addEdge("Programming Logic","Html",false);
    g2.addEdge("Programming Logic","python",false);
    g2.addEdge("Programming Logic","java",false);
    g2.addEdge("Programming Logic","C++",false);
    g2.topologicalSort();
    
}