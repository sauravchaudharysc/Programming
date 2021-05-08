//Cycle detection is Unidirected Graph using DFS
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
    bool isCyclicHelper(T node,map<T,bool>&visited,T parent){
        visited[node]= true;
        for(T neighbour :adjList[node] ){
            if(!visited[neighbour]){
                bool cycle=isCyclicHelper(neighbour,visited,node); //for each neighbour we update parent
                if(cycle){
                    return true;
                }
            }
            //we arrive here if we find if a neighbour is already visited
            //we check if its neighbour isnt parent if yes then there exist cycle
            else if(neighbour!=parent){
                return true;                
            }
        }
        return false;
    }
    bool isCyclicDFS()
    {
        //A map is used to mark the visited node
        map<T,bool> visited;
        //Recursive apporach so we make a parent and pass it in every iteration
        //keep updating for every node
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool ans=isCyclicHelper(node,visited,node);
                if(ans==true){
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
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(0,4);
    g2.addEdge(2,4);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    g2.print();
    if(g2.isCyclicDFS()){
        cout<<"yes cycle found";
    }else{
        cout<<"No ";
    }
}