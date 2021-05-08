/*
A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

Check img.png in same dir
If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1

Sample Output
1
*/
#include<bits/stdc++.h>
using namespace std;

int board[10][10];
int n,hi=0;
//Movements
int x[]={-2,-2,-1,-1,1,1,2,2};
int y[]={-1,1,-2,2,-2,2,-1,1};

void knightTour(int board[][10],int row,int col,int count){
    if(row<0 || col<0 || row>=n || col>=n || board[row][col]==0){
        return;
    }
    hi=max(hi,count+1);
    
    //Mark the current square cell
    board[row][col]=0;
    
    //Travel the direction
    for(int i=0;i<8;i++){
        knightTour(board,row+x[i],col+y[i],count+1);
    }
    //Backtrack
    board[row][col]=1;
}

int main(){
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j])
                sum++; // sum stores total number of valid cells on chessboard
        }
    }
    knightTour(board,0,0,0);
    cout<<sum-hi;
}