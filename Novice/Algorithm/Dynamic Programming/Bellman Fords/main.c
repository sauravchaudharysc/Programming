/*Test Case 
7
10
1 2 6
1 3 5
1 4 5
4 3 -2
3 2 -2
2 5 -1
3 5 1
4 6 -1
6 7 3
5 7 3
1*/
#include<stdio.h>
#include<stdlib.h>
#define INF 99999

//An Structure to contain the edges in graph
struct edge{
    int source;
    int destination;
    int weight;
};

typedef struct edge Edge;

//Bellmans Ford Algorithm
void BellmansFord(Edge *edges,int distance[],int v,int e){
    
    //Relaxation for v-1 times over all the edges
    for(int i=1;i<=v-1;i++){
        for(int j=0;j<e;j++){
            int src=edges[j].source;
            int dest=edges[j].destination;
            int wt=edges[j].weight;
            //Distance array is updated if small distance found
            if(distance[src]!=INF && distance[src]+wt < distance[dest]){
                distance[dest]=distance[src]+wt;
            }
        }
    }
    
     //Check for negative edge cycle
    for(int j=0;j<e;j++){
        int src = edges[j].source;
        int dest = edges[j].destination;
        int wt = edges[j].weight;
 
        //Relaxation
        if(distance[src]!=INF && distance[src] + wt < distance[dest]){
            printf("Graph has negative cycle");
                    return;
        }
    }
    
    for(int i=1;i<=v;i++) {
         printf("%d  - %d\n",i,distance[i]);
    }
    return;
}
int main()
{
    //Vertex
    int v;
    //Edge
    int e;
    scanf("%d %d",&v,&e);
    //An array of edges so we can relaxe them accordingly done in Algorithm
    Edge *edges= (Edge*)malloc(sizeof(Edge));
    for(int i=0;i<e;i++){
        scanf("%d",&edges[i].source);
        scanf("%d",&edges[i].destination);
        scanf("%d",&edges[i].weight);
    }
    //Choose the source from where we need to find shortest path
    int source;
    scanf("%d",&source);
    int distance[v+1];
        for(int i=1;i<=v;i++){
            if(i==source) {
                distance[i] = 0;
            }else {
                distance[i] = INF;
            }
        } 
    BellmansFord(edges,distance,v,e);    
}