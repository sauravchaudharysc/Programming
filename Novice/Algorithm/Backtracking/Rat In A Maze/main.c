#include<stdio.h>
#include<stdbool.h>
#define V 4

bool isSafe(int graph[][V],int row,int col){
    if(graph[row][col]==0){
        return false;
    }
     
     if(row>V || col>V){
         return false;
     }
    return true;
}

//Main Function
bool ratinAMaze(int graph[][V],int soln[][V],int row,int col){
    //Base Case 
    if(row == V && col == V){
         for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                printf("%d ",soln[i][j]);
            }
            printf("\n");
         }
        return true; 
    }    
     
     if(isSafe(graph,row,col)){
         soln[row][col]=1;
         bool rest_of = ratinAMaze(graph,soln,row+1,col);
         if(rest_of){
             return true;
         }
         rest_of = ratinAMaze(graph,soln,row,col+1);
         if(rest_of){
             return true;
         }
         soln[row][col]=0;
     }
    return false;
}
int main()
{
     int graph[V][V] = {{1, 0, 0, 0},  
                        {1, 1, 0, 1},  
                        {0, 1, 0, 0},  
                        {1, 1, 1, 1}};  
    int soln[V][V];
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            soln[i][j]=0;
        }
    }
        
    if(ratinAMaze(graph,soln,0,0)){
        printf(" ");
    }else{
        printf("No path found");
    }
}