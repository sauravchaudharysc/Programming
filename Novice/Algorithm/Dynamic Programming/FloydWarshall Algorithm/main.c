/*All Pairs Shortest Path(Floyd Warshall Algorithm)
This algorithm gives the shortest path between each pair of vertices.We can run Dijkstra algorithm for all pair of vertices and get the all pair shortest path but it's complexity will be O(n^3).This can be solved by using greedy methos.Let see how can we solve it using dynamic programming. 

Dynamic Programming says the each step we take some decision.I will try find a shortest path from one verter to other vertex via any intermediate vertex.*/
#include<stdio.h>
#define V 4
#define INF 9999

void printSolution(int temp[][V]);

int min(int x,int y){
    return ((x<y)?x:y);
}

void floydWarshallAlgorithm(int graph[][V]){
    int temp[V][V];
    /*Copy the input matrix into the temp array.*/
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            temp[i][j]=graph[i][j];
        }
    } 
    /*We cosinder a vertex keep that vertex as intermediate and 
    calculate the distance
    1st Iteration For Making each vertex one by one as intermediate vertex
    2nd Iteration For traversal of rows and 3rd for column traversal.Each row
    denotes a vertex and for that vertex we check all the vertex where k being the 
    intermediate one*/
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                temp[i][j]=min(temp[i][j],temp[i][k]+temp[k][j]);
            }
        }
    //remove the comment to see the changes at each row Iteration    
    // printSolution(temp);   
    } 
     printSolution(temp);
}
void printSolution(int temp[][V]){
    printf("The following matrix shows the shortest distances between every pair of vertices \n");  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (temp[i][j] == INF)  
                printf("INF\t");  
            else
                printf("%d\t",temp[i][j]);  
        }  
        printf("\n");  
    }  
}
int main()
{
   /*Let us create the following weighted graph  
         10  
    (0)------->(3)  
     |         /|\  
    5|          |  
     |          | 1  
    \|/         |  
    (1)------->(2)  
            3     */
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    floydWarshallAlgorithm(graph);     
}