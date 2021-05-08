#include<stdio.h>
#include<stdbool.h>


bool canPlace(int mat[][9],int row,int col,int n,int number)
{
    //To Check The Cell Entire Row And Entire column
    for(int x=0;x<n;x++)
    {
        if(mat[x][col]==number||mat[row][x]==number)
        {
            return false;
        }
    }
    int rn=sqrt(n);
    int sx=(row/rn)*rn;
    int sy=(col/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int mat[9][9],int row,int col,int n)
{
    //Base case
    if(row==n) //Row traversal is equal to n
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
       printf("\n");
        return true;
    }
    //Case for row-end i.e reach the end of row by traversal of columns
    if(col==n)
    {
        return sudokuSolver(mat,row+1,0,n);
    }
    //Skip the pre-filled Cell
    if(mat[row][col]!=0)
    {
        return sudokuSolver(mat,row,col+1,n); //Just change the column
    }
    //Recursive Case
    //Fill the current cell with possible option
    for(int number=1;number<=n;number++)
    {
        if(canPlace(mat,row,col,n,number))
        {
            mat[row][col]=number;
            bool rest_of_the_sudoku=sudokuSolver(mat,row,col+1,n); //Rest of the sudoku is solved
            if(rest_of_the_sudoku)
            {
                return true;
            }
        }
    }
    mat[row][col]=0; //If the entire number is traversed and it cant be filled in the current cell. So backtrack it.
    return false;
}

int main()
{
    int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };

    printf("%d\n",sudokuSolver(mat,0,0,9));
}