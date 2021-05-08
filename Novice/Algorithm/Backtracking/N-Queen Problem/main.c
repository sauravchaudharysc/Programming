#include<stdio.h>
#include<stdbool.h>
//An helper function which checks is the place safe for queen to be placed
bool isSafe(int board [][10],int i,int j,int n){
    //To check column
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    //Left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    
    //Right Diagonal
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNQueen(int board[][10],int i,int n){
    //We traversed all the row means we are successful in keeping all the queens
    if(i==n){
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j])
                {
                    printf("Q ");
                }
                else
                {
                    printf("_ ");
                }
            }
            printf("\n");
        }
        return true;
    }
    //Recursive Case 
    /*We place a queen and take assumption that remaining sub-grid the queen
    are automatically placed by recursion. We put a queen by the for loop and
    order rest places to recursion ja bhai tu karke aa.*/
    //Try to place the queen in current row
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            bool rest_of_the_queens=solveNQueen(board,i+1,n);
            if(rest_of_the_queens){
                return true;
            }
            //Backtrack,since our assumption is false so we need to correct it.
            board[i][j]=0;
        }
    }
    //Tried all position in current row
    return false;
}
int main()
{
    int board[10][10]={0};
    solveNQueen(board,0,4);
}