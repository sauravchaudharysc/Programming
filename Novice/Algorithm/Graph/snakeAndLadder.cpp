//Snakes and Ladder Problem
/*You are given a board where it contain snakes and ladder.If you climb a stair you
reach a higher point and if bitten by snake then you reach lower point.You are given a dice
and you can throw a number of your choice.Minimum number of dice moves to win the game.
You can throw dice from 0 to 6.
<br>
The whole thing can be represented as a graph.So there are 37 vertices.Each Node has
some neighbour.<br>
<br>
So initially we are at zero.If we throw a dice from zero you can reach 1,15,3,4,7,6.
We reach 15,7 because there is ladder at 2,5 which act as transient point.<br>
So if we are at one.If we throw a dice from zero you can reach 15,3,4,7,6,8.
We reach 15,7 because there is ladder at 2,5 which act as transient point.<br>
From every node v there are some edges which are going to v+1,v+2,v+3...v+6 vertices.<br>
Since the cost is same for every dice throw and you can only climb up from stair cant
come back or only move forward so it is unweighted directed graph.<br>
I am going to make a board array and initialise it zero.And add some exception.<br>
On reaching 2 we move to 15.On reaching 2 we get a jump of 13.On reaching 5 we move to 7.
On reaching 5 we get a jump of 2.<br>
board[2]=13,board[5]=2.<br>
In case of snake.If we reach 17 then we are bitten by snake and we go to 4.<br>
board[17]=-13;
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
        // for(auto i:adjList){
        //     T node=i.first;
        //     cout<<"Dist of neighbour from "<<src<<" is "<<dist[node]<<endl;
        // }
        //You can use the parent because you have stored the path.
        //So i backtrack from parent to see the taken path
        T temp=dest;
        while(temp!=src){
            cout<<temp<<" <-- ";
            temp=parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }
};

int main()
{
    Graph<int> g;
    int board[37]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    //Graph Creation
    for(int u=0;u<=36;u++)
    {
        for(int dice=1;dice<=6;dice++){
            int v=u+dice+board[u+dice];
            g.addEdge(u,v,false);//False because it is unidirectional
        }
    }
    cout<<"The shortest dist is "<<g.bfs(0,36);
}


