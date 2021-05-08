#include<bits/stdc++.h>
using namespace std;
const int D=8;
bool canPlace(int board[D][D],int n,int r,int c){
    return r>=0 && r<n && c>=0 && c<n && board[r][c]==0;
}

bool knightTourProblem(int board[D][D],int n,int move,int currRow,int currCol)
{
    if(move==n*n)
    {
        return true;
    }
    int rowDir[]={2,1,-1,-2,-2,-1,1,2};
    int colDir[]={1,2,2,1,-1,-2,-2,-1};
    for(int curDir=0;curDir<n;curDir++)
    {
        int nextRow=currRow+rowDir[curDir];
        int nextCol=currCol+colDir[curDir];
        if(canPlace(board,n,nextRow,nextCol)){
            board[nextRow][nextCol]=move+1; //Place the knight
            bool rest_of_the_board=knightTourProblem(board,n,move+1,nextRow,nextCol);
            if(rest_of_the_board)
            {
                return true;
            }
            board[nextRow][nextCol]=0; //BackTracking i.e the position is not able to accept the knight so remove the knight.
        }
    }
    return false;
}

void printBoard(int board[D][D],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(3)<< board[i][j] <<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int board[D][D]={0};
    int n;
    cin>>n;
    board[0][0]=1;
    bool ans=knightTourProblem(board,n,1,0,0);
    if(ans)
    {
        printBoard(board,n);
    }
    else
    {
        cout<<"Haha";
    }
}