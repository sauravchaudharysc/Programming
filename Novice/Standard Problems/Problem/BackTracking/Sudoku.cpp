/*You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100][100];
bool canPlace(ll dp[][100],ll row,ll col,ll n,int number){
    //To Check Entire Row And Column for the number
    for(ll x=0;x<n;x++){
            if(dp[row][x]==number || dp[x][col]==number){
                return false;
            }
        
    }
    
    //To check the box in sudoku table 
    ll rn = sqrt(n);
    ll sx = (row/rn)*rn;
    ll sy = (col/rn)*rn;
    for(ll x=sx;x<sx+rn;x++){
        for(ll y=sy;y<sy+rn;y++){
            if(dp[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(ll dp[][100],ll row,ll col,ll n){
    //Base Case
    if(row==n){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //If Row is filled
    if(col==n){
        return sudokuSolver(dp,row+1,0,n);
    }
    //If the cell is filled then just shift to next column
    if(dp[row][col]!=0){
        return sudokuSolver(dp,row,col+1,n);
    }
    //Recursive Case 
    //Fill the current cell with possible option 
    for(int number=1;number<=9;number++){
        if(canPlace(dp,row,col,n,number)){
            dp[row][col] = number;
            bool rest_Of_The_Sudoku=sudokuSolver(dp,row,col+1,n);
            if(rest_Of_The_Sudoku){
                return true;
            }
        }
    }
    //The entire number cant be placed so we backtrack
    dp[row][col]=0;
    return false;
}

int main()
{
    ll n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>dp[i][j];
        }
    }
   if(sudokuSolver(dp,0,0,n)){
       cout<<endl;
   }
}