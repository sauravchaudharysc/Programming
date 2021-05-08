#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>>m;
    public:
     void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
     }
     void printAdj(){
         //Iterate over all the rows
         for(auto j:m){
            T node=j.first;
            cout<<node<<" --> ";
            //Iterate over all the columns
            for(auto i:j.second){
                cout<<"("<<i.first<<","<<i.second<<")";
            }
            cout<<endl; 
         }
     }
     void dijkstraSSSP(T src){
        //An map to store the city name and distance
        unordered_map<T,int> dist;
        //Set all disance to infinity
        //dist[j.first]=INT_MAX means we go to every city and set it distance infinity
        for(auto j:m){
            dist[j.first]=INT_MAX;
        }
        //Make a set to find out a node with minimum distance
        /*First parameter distance rakha h kyuki set sorting on the basis of 
          first paramter karti h and mujhe wohi chaiyeh*/
        set<pair<int,T>>s;
        dist[src]=0;
        //Jo source node aaya usko insert kardia and distance 0 bhi kardia
        s.insert(make_pair(0,src));
        //Set becomes empty when all city distance are relaxed
        while(!s.empty()){
            //Find the pair at the front
            auto p= *(s.begin());
            //Name of the node
            //See the above set declaration we see distance is first and city name is second
            int nodeDist = p.first;
            T node = p.second;
            //Erase it because the distance has been finalised 
            //Because we choose the node which has minimum distance and that is final
            s.erase(s.begin());
            //Iterate over the neighbours of current node
            //Every child belonging to the adjacency list of current node
            for(auto childPair : m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    //Distance between the parent node and neighbour node
                    T dest = childPair.first;                    
                    //In the set updation isnt possible
                    //So to perform this we remove that pair and insert the new pair
                    //dist[dest] because distance is stored in dist map
                    auto f = s.find(make_pair(dist[dest],dest));
                    //f is an iterator and if it is found then it doesnt reach end
                      if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=nodeDist + childPair.second;
                    //Insert in the map the new updated distance and name of the city
                    s.insert(make_pair(dist[dest],dest));;
                }
            }  
        }
        //Lets print distance to all other node from source
        for(auto d:dist){
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }
     }
};


int main()
{
 Graph<string> g;
 g.addEdge("Kathmandu","Pokhara",4);
 g.addEdge("Kathmandu","Birgunj",1);
 g.addEdge("Pokhara","Birgunj",2);
 g.addEdge("Pokhara","Kalaiya",8);
 g.addEdge("Kalaiya","Janakpur",3);
 g.addEdge("Birgunj","Biratnagar",1);
 g.addEdge("Biratnagar","Janakpur",2);
 g.printAdj();
 g.dijkstraSSSP("Kathmandu");
}