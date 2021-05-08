//Here DFS IS filling all the position by visiting all the unvisited matrix

#include<bits/stdc++.h>
using namespace std;
int R;
int C;
void printMat(char input[][50]){
    for(i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}
//To travel W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void floodFill(char mat[][50],int i,int j,char ch,char color){
    //Base case -Matrix bounds
    if(i<0 || j<0 || i>=R||j>=C){
        return;
    }
    //Figure boundary condition
    if(mat[i][j]!=ch){
        return;
    }
    mat[i][j]=color;
    for(k=0;k<4;k++){
        floodFill(mat,i+dx[k],j+dy[k],ch,color);
    }
}  

int main(){
    cin>>R>>C;
    char input[15][50];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodFill(input,8,13,'.','r');
}