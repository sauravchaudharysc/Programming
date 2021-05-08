#include<bits/stdc++.h>
using namespace std;

#define M 8 
#define N 8 
int screen[M][N] =   {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
                     
 void floodfill(int x,int y,int prevC,int newC){
     if(screen[x][y]!=prevC){
         return;
     }
     if(screen[x][y]==newC){
         return;
     }
     screen[x][y]=newC;
     floodfill(x-1,y,prevC,newC);
     floodfill(x,y-1,prevC,newC);
     floodfill(x+1,y,prevC,newC);
    floodfill(x,y+1,prevC,newC);     
 }
 
 int main(){
     floodfill(4, 4,2,3); 
     for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << screen[i][j] << " "; 
        cout << endl; 
    } 
 }