#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
/*Floyd Warshall Algorithm :- In this we need to find ALl Pairs Shortest Path. 
So We Visit all the vertices and find the shortest path of it to other vertices.*/
void printSolution(int temp[][V]);
void floydWarshallAlgorithm(int graph[][V])
{
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
    2nd Iteration For traversal of rows and 3rd for column traversal*/
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                temp[i][j]=min(temp[i][j],temp[i][k]+temp[k][j]);
            }
        }
    }
    printSolution(temp);
}
void printSolution(int temp[][V]){
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (temp[i][j] == INF)  
                cout<<"INF"<<"\t";  
            else
                cout<<temp[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
}
int main()  
{  
    /* source:- Geeks .Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    floydWarshallAlgorithm(graph);  
}  
