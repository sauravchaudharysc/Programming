


#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
void wordWrap(int wl[],int size,int W)
{
    int extraSpace[size][size]={0};
    int cost[size][size]={0};
    /*This For Loop calculates the maximum word to get fit*/
    for(int i=0;i<size;i++){
        extraSpace[i][i]=W-wl[i];
        for(int j=i+1;j<size;j++){
            extraSpace[i][j]=extraSpace[i][j-1]-wl[j]-1;
        }
    }
    /*To calculate cost we take the square of the extraSpace array*/
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(extraSpace[i][j]<0){
                cost[i][j]=INF;                
            }else{
                cost[i][j]=extraSpace[i][j]*extraSpace[i][j];
            }
        }
    }
    /*Remove the comment to see the cost array output
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    /*In this min cost array we find the cost to place each word in Line and subsequent
    steps will find the minimum cost and hence we will put that in result array*/
    int minCost[size];
    int result[size];
    for(int i=size-1; i>=0;i--){
        minCost[i]= cost[i][size-1];
        result[i]=size;
        /*This j loop checks the split at each position and then the split with minimum
        cost is considered*/
        for(int j=size-1;j>i;j--){
            if(cost[i][j-1]==INF){
                continue;
            }
            if(minCost[i]>minCost[j]+cost[i][j-1]){
                minCost[i] = minCost[j] + cost[i][j-1];
                result[i] = j; 
            }
        }
    }
    for(int j=0;j<size;j++){
        cout<<result[j]<<"\t";
    }
        cout<<endl;
}
int main()
{
    string words[] = {"hii","hi","hi","hiiii"};
    int wl[]={3,2,2,5}; //Length of each consectutive words
    int size=sizeof(wl)/sizeof(wl[0]);
    int MaxWidth=6;
    wordWrap(wl,size,MaxWidth);
}