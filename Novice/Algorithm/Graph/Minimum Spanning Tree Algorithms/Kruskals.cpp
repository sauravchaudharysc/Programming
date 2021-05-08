#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
class Set{
 public:
 int rank;
 int parent;
};
//retun the parent of the set
//In union rank algorithm we initially the parent of all element to those element itself
int find(Set *set,int i){
  if(set[i].parent!=i){
      set[i].parent=find(set,set[i].parent);
  }    
  return set[i].parent;
}
void Union(Set *set,int v1,int v2){
    int v1_root=find(set,v1); 
    int v2_root=find(set,v2);
    //We will check rank of two set,if a particular set has lesser rank then lower rank parent is updated
    if(set[v1_root].rank<set[v2_root].rank){
        set[v1_root].parent=v2_root;
    }else if(set[v1_root].rank>set[v2_root].rank){
        set[v2_root].parent=v1_root;
    }else{
        set[v2_root].parent=v1_root;
        set[v1_root].rank++;
    }    
}
void Kruskals(Edge *input,int v,int e)
{
    //It will sort the input array on the basis of weight of edges
    sort(input,input+e,compare);
    //For a tree no of edges is vertex-1
    Edge *output=new Edge[v-1];
    //Initialised the set for all vertices
    Set *set = new Set[v];
    //for every set
    for(int i=0;i<v;i++){
        set[i].rank=0; //Initially all rank is zero
        set[i].parent=i; //Each node is a parent of own
    }
    int counter=0,i=0;
    while(counter<v-1){
        Edge currentEdge=input[i]; //We have taken the edge with minimum weight
        int sourceParent=find(set,currentEdge.src); //Find the parent of source vertex
        int destinationParent=find(set,currentEdge.dest); //Find the parent of distance vertex
        //if they arent same they dont belong to same set so there parent are different
        if(sourceParent!=destinationParent){
            output[counter]=currentEdge;
            //Current set meh union kardia predefine function h
            Union(set,sourceParent,destinationParent);
            counter++; //increase the counter
        }
        i++;
    }
    for(int m=0;m<v-1;m++){
        cout<<output[m].src<<"---"<<output[m].dest<<" with weight"<<output[m].weight<<endl;
    }
}
/*
7                                                                                         
8                                                                                         
0 3 4                                                                                     
0 1 6                                                                                     
1 2 5                                                                                     
3 2 7                                                                                     
3 4 2                                                                                     
4 5 4                                                                                     
5 6 1                                                                                     
4 6 3*/
int main()
{
    //No of vertices and no of edges
    int v,e;
    cin>>v>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].src=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    Kruskals(input,v,e);
    return 0;    
}