#include<stdio.h>

//To sum the frequency from i to j
int sum(int i, int j,int freq[])  
{  
    int s = 0;  
    for (int k = i; k <= j; k++)  
    s += freq[k];  
    return s;  
}  

void optimalBinarySearchTree(int freq[],int n){
 int dp[n][n];
 
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
      dp[i][j]=0;
     }
 }
 //Diagonal 0 each element acts as a root so simply the frequency is written
 for(int i=0;i<n;i++){
     dp[i][i]=freq[i];
 }
 
 //Diagonal 1 onwards
 //The row and column determines the no of nodes to considered starting from 2.
 for(int diagonal=1;diagonal<n;diagonal++){
     for(int row=0;row<n-diagonal;row++){
         int col=row+diagonal;
         //Consider the current to be maximum
          dp[row][col]=9999;
          //Make each node root one by one and compare each one of their cost
         for(int k=row;k<=col;k++){
             int cost=sum(row,col,freq)+((k>row)? dp[row][k-1]:0)+((k<col)? dp[k+1][col]:0);
            //The root node which give minimum cost is considered
            if(cost<dp[row][col]){
                dp[row][col]=cost;
            } 
         }
     }
 }
 printf("%d ",dp[0][n-1]);
    
}
int main(){
    int keys[] = {10, 12, 20};  
    int freq[] = {34, 8, 50};  
    int n = sizeof(keys)/sizeof(keys[0]);  
    optimalBinarySearchTree(freq,n);   
}