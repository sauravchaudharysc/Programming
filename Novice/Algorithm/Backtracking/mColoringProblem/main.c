#include<stdio.h>
#include<stdbool.h>
#define V 4
bool isSafe(int graph[][V],int color[],int c,int v){
    //The for loop traverse the adjacency matrix column respective to row v
    for(int i=0;i<V;i++){
        //Check is there an edge and 
       // the color selected matches the edge connected vertex color
        if(graph[v][i] && c ==color[i]){
            return false;
        }
    }
    return true;
}
bool graphColoring(int graph[][V],int m,int color[],int v){
    
    //Base case
    //All the vertex are colored 
    if(v==V){
        printf("Solution Exists:"); 
            for (int i = 0; i < V; i++)
            { 
                printf("%d ",color[i]);
            }
            //If all the way require mark this false
            return true;
    }
    
    
    
    //We have to choose from the m-Colors and color the graph
    for(int c=1;c<=m;c++){
        //Check if assignment of a color to a vertex is fine or not
        //v is here for vertex and c is for color choosed
        if(isSafe(graph,color,c,v)){
            //if safe mark the vertex with that color 
            color[v]=c;
            //Assigning Rest Vertices Colors Recursively 
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
int main()
{
     int graph[V][V]={ {0,1,1,1},
                       {1,0,1,0},
                       {1,1,0,1},
                       {1,0,1,0}};
    int m=3;
    int color[V]={0};
    
    if(graphColoring(graph,m,color,0))
    {
        printf(" ");
    }
    else
    {
        printf("Solution doesn't exist");
    }
}