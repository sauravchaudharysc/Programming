#include<bits/stdc++.h>
using namespace std;
#define V 5
bool isSafe(int v,int graph[V][V],int path[],int pos)
{
    if(graph[path[pos-1]][v]==0) //To check edge connection between the last vertex and new vertex
    return false; //If no Vertex then that vertex isnt acceptable
    for(int i=0;i<pos;i++) //To check whether the given vertex is included or not
    {
        if(path[i]==v)
        {
            return false;
        }
    }
    return true;
}
bool hamiltonCycle(int graph[V][V],int path[],int pos)
{
    //Base case
    if(pos==V) //The Path Array Get Filled. All Vertices Are Covered.
    {
        if(graph[path[pos-1]][path[0]]==1) //Last Vertex of Path Array And First Vertex contain path.Then they form a cycle.
        {
             for (int i = 0; i < V; i++) 
                    cout<<setw(3)<<path[i];
            cout<<setw(3)<<path[0];        
            return true;        
        }
        else{
            return false;            
        }
    }
    
    for(int v=1;v<V;v++)
    {
        if(isSafe(v,graph,path,pos)){
            path[pos]=v;
            bool rest_Of_The_Path=hamiltonCycle(graph,path,pos+1);
            if(rest_Of_The_Path)
             {
                return true;
             }
             
            path[pos]=-1;
        }
    }
    return false; //No Vertex can be added to the path array. Return back and correct previous
}
int main()
{
    int graph[V][V] =   {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 1}, 
                         {0, 1, 1, 1, 0}, 
                        };
    int path[V]={-1}; //Store Paths
    path[0]={0}; //Start from Vertex Zero
        if(hamiltonCycle(graph,path,1))
        {
            cout<<" ";
        }
        else
        {
            cout<<"No Hamilton Cycle";
        }
}