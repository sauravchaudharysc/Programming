//Implementing Adjacency List
/*
To Create array of list:- 
    int *a =new int[V]
The array is created dynamically because the no of vertices is decided at runtime.
So we need to to create it dynamically.But this is not going to be array of integer
this is going to be array of linked list.
list<int>*l =new list<int>[v] */
#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
    int V;
    list <int> *l;
    public:
        Graph(int V){
            this->V=V;
            l= new list<int>[V]; //Array of linked list
        }
    //Here bidir assures that there is connection between both of the vertices.
    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-> ";
            //l[i] is linked list . To iterate over linked list we use for:Each loop
            for(int Vertex: l[i]){
                cout<<Vertex<<" ,";
            }
            cout<<endl;
        }
    }
};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.printAdjList();
    return 0;
}