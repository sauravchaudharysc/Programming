#include<bits/stdc++.h>
using namespace std;
int main()
{
    //The vertices are divided into no of stages
    int stages=4;
    //The total no of vertices
    int n=8;
    //The array of cost gives the cost from that vertex to sink
    //The array of d gives the next vertex in his path to get shortest path.
    //The array of path stores the shortest path
    int cost[9],d[9],path[stages+1];
    int c[9][9]={
      {0,0,0,0,0,0,0,0,0},
      {0,0,2,1,3,0,0,0,0},
      {0,0,0,0,2,3,0,0,0},
      {0,0,0,0,6,7,0,0,0},
      {0,0,0,0,0,6,8,9,0},
      {0,0,0,0,0,0,0,0,6},
      {0,0,0,0,0,0,0,0,4},
      {0,0,0,0,0,0,0,0,5},
      {0,0,0,0,0,0,0,0,0},
    };
    //Sink Vertex cost is zero
    cost[8]=0;
    /*Start from the second last stage and we can iterate simply because 
    there will no edge in same stage*/
    for(int i=n-1;i>=1;i--){
        int ans=INT_MAX;
        for(int k=i+1;k<=n;k++){
            if(c[i][k]!=0 && c[i][k]+cost[k]<ans){
                ans=min(ans,c[i][k]+cost[k]);
                d[i]=k;
            }
        }
        cost[i]=ans;
    }
    //Now we find the path using the array of d which gives the next vertex in his path to get shortest path. 
    path[1]=1;
    path[stages]=n;
    for(int i=2;i<stages;i++){
        path[i]=d[path[i-1]];
    }
    
    //Print the shortest path
    for(int i=1;i<=stages;i++){
        cout<<path[i]<<" ";
    }
}