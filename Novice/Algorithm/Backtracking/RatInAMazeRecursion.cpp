#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[][4],int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return true;
	}

	if(sr>er or sc>ec){
		return false;
	}

	if(maze[sr][sc]=='X'){
		return false;
	}

	bool horizontal = ratInMaze(maze,sr,sc+1,er,ec);
	bool vertical = ratInMaze(maze,sr+1,sc,er,ec);

	return horizontal or vertical;
}
int main()
{
	char maze[][4] = {
      	{'0','0','0','0'},
    	{'0','0','0','0'},
      	{'0','0','X','0'},
     	{'0','X','0','0'},
    };

 			 cout<<ratInMaze(maze,0,0,3,3)<<endl;

}