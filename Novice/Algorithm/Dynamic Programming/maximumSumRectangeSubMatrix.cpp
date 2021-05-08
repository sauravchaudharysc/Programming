#include<bits/stdc++.h>
using namespace std;
#define ROW 4  
#define COL 5  
int kadanes(int temp[],int *start,int *end){
    int currsum=temp[0];
    int maxSum=temp[0];
    for(int i=1;i<ROW;i++){
         currsum += temp[i];
        if(currsum<0){
            *start=i;
            currsum=0;
        }
        if(maxSum<currsum){
            maxSum=currsum;
            *end=i;
        }
    }
    return maxSum;
}
/*Here we iterate from the left column to right column.First we make the left at index 0
and traverse For each column we store them in temp 1d-array which is size of row. And we 
find the maxSum and update. Then after a complete column traversal we increment the left
do the same operation.In this way get the maxSum.We keep a start and end and pass it by call
by reference to update the top left and and top bottom position and use it to print the matrix*/
void findMaxSum(int input[ROW][COL])
{
    int maxSum = INT_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom;
    int temp[ROW];
    int start,end;
    for(int left=0;left<COL;left++){
            memset(temp,0,sizeof(temp));
        for(int right=left;right<COL;right++){
            for(int i=0;i<ROW;i++){
                temp[i]+=input[i][right];
            }
            int sum=kadanes(temp,&start,&end);
            if(maxSum<sum){
                maxSum=sum;
                finalLeft=left;
                finalRight=right;
                finalTop=start;
                finalBottom=end;
            }
        }
    }
    cout << "(Top, Left) (" << finalTop 
         << ", " << finalLeft << ")" << endl;  
    cout << "(Bottom, Right) (" << finalBottom  
         << ", " << finalRight << ")" << endl;  
    cout << "Max sum is: " << maxSum << endl; 
}

int main()
{
int input[ROW][COL] = {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};  
  
    findMaxSum(input); 
}