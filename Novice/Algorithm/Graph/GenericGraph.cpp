/*Now we are going to represent adjacency list for specific type of data.Now we are
going to make generic graph where node can contain any data type.So we can use 
HashMap and template to make it more functionable.*/
#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
  map<T,list<T>>adjList;
  public:
    Graph(){
        
    }
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
};

int main()
{
    Graph<string> g;
    g.addEdge("Ranvijay","Rk");
    g.addEdge("Sisodia","Physics");
    g.addEdge("Animesh","Self called scientist");
    g.print();
    
    Graph<int> g2;
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,1);
    g2.print();
}