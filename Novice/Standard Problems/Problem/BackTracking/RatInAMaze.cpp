#include<bits/stdc++.h>
using namespace std;
char maze[1005][1005];
char ans[1005][1005];
bool RatInAMaze(char maze[][1005],int Row,int Col,int N,int M){
    if(Row==N and Col==M){
        ans[Row][Col]='1';
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }    
        return true;
    }
    if(Row > N or Col > M){
        return false;
    }
    if(maze[Row][Col]=='X'){
        return false;
    }
    ans[Row][Col]='1';
    bool horizontal = RatInAMaze(maze,Row,Col+1,N,M);
    if(horizontal){
        return true;
    }
    bool vertical = RatInAMaze(maze,Row+1,Col,N,M);
    if(vertical){
        return true;
    }
    ans[Row][Col]='0';
    return false;
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maze[i][j];
            ans[i][j]='0';
        }
    }
    if(RatInAMaze(maze,0,0,N-1,M-1)){
            cout<<"";
    }else{
        cout<<"NO PATH FOUND";
    }
}