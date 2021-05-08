/*This mask can have optimization because mask can take 2^n values.
Total no of distinct states = 2^n * n .
So i can make 2-d dp table to store the value of same overlapping
sub-problems*/
#include<stdio.h>
#define INT_MAX 99999
int dp[16][4];
//Total no of cities
int n=4;

//Adjacency matrix which defines the graph
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

//If all cities has been visited
//This makes a 4-bit number and each representing a city
int VISITED_ALL = (1<<n)-1; 


//Main Function
int tsp(int mask,int pos){
	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	
	//Look Up 
	if(dp[mask][pos]!=-1){
	    return dp[mask][pos];
	}
	
	//To get an final answer
    int ans = INT_MAX;
	//Try to go to an unvisited city 
	for(int city=0; city<n;city++){
		//Check the ith bit in city and check visited or not
		 if((mask&(1<<city))==0){
		 	/*The original mask is 0001 and we take or with the city going to visit
			The 1<<city gives the idea of city which we are going to visit*/
		 	int newAns= dist[pos][city]+ tsp(mask|(1<<city),city);
		 	if(newAns<ans){
		 	ans=newAns;
		 	}
		 }
	}
	return dp[mask][pos]=ans;
}

int main()
{
    for(int i=0;i<16;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=-1;
        }
    }
	int x=tsp(1,0);  
	printf("The minimum distance for Travelling Salesman is %d",x);
}