#include<bits/stdc++.h>
using namespace std;
long long int mat[501][501];
int main(){
    for(long long int i=0;i<=500;i++){
        for(long long int j=0;j<=500;j++){
            mat[i][j]=INT_MAX;
        }
    }
    long long int n,m,q;
    cin>>n>>m>>q;
    for(long long int i=1;i<=n;i++){
        mat[i][i]=0;
    }
    for(long long int i=0;i<m;i++){
        long long int u,v,w;
        cin>>u>>v>>w;
        mat[u][v]=w;
        mat[v][u]=w;
    }
    for(long long int k=1;k<=n;k++){
        for(long long int i=1;i<=n;i++){
            for(long long int j=1;j<=n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    for(long long int i=0;i<q;i++){
        long long int x,y;
        cin>>x>>y;
        if(mat[x][y]==INT_MAX){
            cout<<"-1"<<endl;
        }else{
            cout<<mat[x][y]<<endl;
        }
    }
}