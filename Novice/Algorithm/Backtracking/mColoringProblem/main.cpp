#include<bits/stdc++.h>
using namespace std;
#define V 4
bool isSafe(int v,int graph[V][V],int color[],int c)
{
    for(int i=0;i<V;i++)
    {
        if(graph[v][i] && c==color[i]) //Returns if there exist a edge connection and collor between the vertices are same
        return false;
    }
    return true;
}

bool graphColoring(int graph[V][V],int m,int color[],int v){
    //Base Case
    if(v==V)
    {
        cout<<"Solution Exists:"<<endl; 
            for (int i = 0; i < V; i++)
            { 
                cout<<color[i]<<" "; 
            }  
        return true;
    }
    //Assigning Colors Recursively
    for(int c=1;c<=m;c++)
    {
        //Check if assignment of color to a vertex is fine
        if(isSafe(v,graph,color,c))
        {
            color[v]=c;
            bool rest_of_the_vertices=graphColoring(graph,m,color,v+1);
            if(rest_of_the_vertices)
            {
                return true;
            }
            color[v]=0;
        }
    }
    return false;
}

int main(){
    int graph[V][V]={ {0,1,1,1},
                       {1,0,1,0},
                       {1,1,0,1},
                       {1,0,1,0}};
    int m=3;
    int color[V]={0};
    
    if(graphColoring(graph,m,color,0))
    {
        cout<<" ";
    }
    else
    {
        cout<<"Solution doesn't exist";
    }
}