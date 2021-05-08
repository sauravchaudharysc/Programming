#include<stdio.h>
#include<stdbool.h>
#define V 5

bool isSafe(int graph[][V],int path[],int v,int pos){
    
    //The starting vertex 
    if(pos==0){
        return true;
    }
    
    //To check is there an edge between the last vertex and current vertex
    if(graph[path[pos-1]][v]==0){
        return false;
    }
    
    //To check is the current vertex already visited or not
    for(int i=0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    //If above all the condition fails , it means the current vertex is okay to be placed
    return true;
}

//Main Function
bool hamiltonCycle(int graph[][V],int path[],int pos){
    //Base case
    //Last vertex of Path Array and First Vertex must contain path between them
    if(pos==V){
        if(graph[path[pos-1]][path[0]]){
            for(int i=0;i<V;i++){
                printf("%d ",path[i]);
            }
            printf("%d ",path[0]);
            return true;
        }else{
        return false;
        }
    }
    for(int v=0;v<V;v++){
        //The position variable is for array index
        /*To check the position is safe or not we pass the graph, the vertex,
        the position,the path array.*/
        if(isSafe(graph,path,v,pos)){
            path[pos]=v;
            bool rest_of_the_vertex=hamiltonCycle(graph,path,pos+1);
            if(rest_of_the_vertex){
                return true;
            }
        }
        //Backtrack
        path[pos]=-1;
    }
    //All the vertex cant be placed . So we might have take wrong path before
    return false;
}
int main()
{
     int graph[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
    
    //The path Array to Store the final result  
    int path[V];
    
    for(int i=0;i<V;i++)
        path[i]=-1;
        
    if(hamiltonCycle(graph,path,0)){
        printf(" ");
    }else{
        printf("No path found");
    }
}