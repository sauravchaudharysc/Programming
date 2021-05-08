#include<bits/stdc++.h>
using namespace std;
bool ratInMaze(char maze[4][4],int soln[4][4],int i,int j,int m,int n){
    if(i==m && j==n)
    {
        soln[m][n]=1;
        	for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"***************"<<endl;

	
        return true;
    }
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    soln[i][j]=1; //Mark 1 to current cell if visited
    bool right=ratInMaze(maze,soln,i,j+1,m,n);
    bool down=ratInMaze(maze,soln,i+1,j,m,n);
    //Backtracking
    soln[i][j]=0;
    if(right||down){
        return true;
    }
    return false;
}
int main()
{
    char maze[][4] = {
      	{'0','0','0','0'},
      	{'0','0','X','0'},
      	{'0','0','0','X'},
      	{'0','X','0','0'},
      };
      int sol[4][4] = {0};
	cout<<ratInMaze(maze,sol,0,0,3,3);
}