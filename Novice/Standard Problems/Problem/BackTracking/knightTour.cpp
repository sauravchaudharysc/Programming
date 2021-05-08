#include<bits/stdc++.h>
using namespace std;

const int D=8; 

//Movements
int x_Movement[]={-2,-2,-1,-1,1,1,2,2};
int y_Movement[]={-1,1,-2,2,-2,2,-1,1};

//Row and Column ,greater than zero and less than n.
//The cell is vacant.
bool canPlace(int board[D][D],int n,int r,int c){
    return (r>=0 && r<n && c>=0 && c<n && board[r][c]==0);
}

void printBoard(int board[D][D],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool knightTour(int board[][D],int n,int move,int x,int y){
    //Base Case 
    if(move == n*n){
        return true;
    }
    
    for(int i=0;i<8;i++){
        int next_X = x + x_Movement[i];
        int next_Y = y + y_Movement[i];
        if(canPlace(board,n,next_X,next_Y)){
            board[next_X][next_Y]=move+1; //Place the knight
            bool rest_Of_The_Board = knightTour(board,n,move+1,next_X,next_Y);
            if(rest_Of_The_Board){
                return true;
            }
            board[next_X][next_Y]=0;
        }
    }
    return false;
}

int main(){
    int board[D][D]={0};
    int n;
    cin>>n;
    //Align the first knight
    board[0][0]=1;
    bool ans = knightTour(board,n,1,0,0);
    if(ans){
        printBoard(board,n);
    }else{
        cout<<"Not Placed";
    }
}