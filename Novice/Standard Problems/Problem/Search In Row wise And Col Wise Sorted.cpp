/*
Let’s start our search from the top-right corner of the array. There are three possible cases.

1.The number we are searching for is greater than the current number. This will ensure, that all the elements in the current row is smaller than the number we are searching for as we are already at the right-most element and the row is sorted. Thus, the entire row gets eliminated and we continue our search on the next row. Here elimination means we won’t search on that row again.
2.The number we are searching for is smaller than the current number. This will ensure, that all the elements in the current column is greater than the number we are searching for. Thus, the entire column gets eliminated and we continue our search on the previous column i.e. the column at the immediate left.
3.The number we are searching for is equal to the current number. This will end our search.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    int mat[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>mat[i][j];
        }
    }
    int flag=0;
    int num;
    cin>>num;
    int j=col-1;
    int i=0;
    int smallest = mat[0][0], largest = mat[row - 1][col - 1]; 
    if (num < smallest || num > largest) 
        return -1;
    while(j>=0 && i<row){
        if(mat[i][j]==num){
                    flag=1;
                    break;
                }else if(mat[i][j]>num){
                    j--;
                }else{
                    i++;
        		}
    }
    if(flag==1){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
}


