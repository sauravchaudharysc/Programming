#include<bits/stdc++.h>
#define R 6
#define C 5
using namespace std;
void printMaxSubSquare(int M[R][C])
{
    int dp[R][C]={0};
    int max_value,max_row,max_col;
    for(int i=0;i<R;i++){
        dp[0][i]=M[0][i];
    }
    for(int i=0;i<C;i++){
        dp[i][0]=M[i][0];
    }
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            if(M[i][j] == 1){
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
            }else{
                dp[i][j]=0;
            }
        }
    }
     max_value=max_row=max_col=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(dp[i][j]>max_value){
                max_value=dp[i][j];
                max_row=i;
                max_col=j;
            }
        }
    }
    for(int i=max_row;i>max_row - max_value ;i--){
	     for(int j=max_col;j>max_col - max_value;j--){
        	cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int  M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};  
                      
    printMaxSubSquare(M);
}