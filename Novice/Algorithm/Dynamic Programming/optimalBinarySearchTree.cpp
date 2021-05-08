#include <bits/stdc++.h> 
using namespace std; 
// A utility function to get sum of array elements 
// freq[i] to freq[j] 
int sum(int freq[], int i, int j) 
{ 
	int s = 0; 
	for (int k = i; k <= j; k++) 
	s += freq[k]; 
	return s; 
}
int optimalSearchTree(int keys[], int freq[], int n) 
{ 
	int cost[n][n];
	/*Initialising all values of cost zero.You can use memset instead of this*/
	for(int i=0;i<n;i++){ for(int j=0;j<n;j++){cost[i][j]=0;}}

	// For a single key, cost is equal to frequency of the key 
	for (int i = 0; i < n; i++){
	    cost[i][i] = freq[i];
	} 
		 
	//Diagonal Reprsents chain length+1
	for (int diagonal = 1; diagonal < n; diagonal++) 
	{ 
		for (int row = 0; row < n-diagonal; row++) 
		{ 
			int column = row+diagonal;
			cost[row][column] = INT_MAX;
			// Try making all keys in interval keys[i..j] as root 
			for (int i = row; i <= column; i++) 
			{ 
			// c = cost when keys[r] becomes root of this subtree 
			int c = ((i > row)? cost[row][i-1]:0) + 
					((i < column)? cost[i+1][column]:0) + 
					sum(freq, row, column); 
			if (c < cost[row][column]) 
				cost[row][column] = c; 
			} 
		} 
	} 
//   for (int i = 0; i < n; i++){
//     for (int j = 0; j < n; j++){
//       cout<<cost[i][j]<<"\t\t";
//     }cout<<endl;
//   }
       return cost[0][n-1]; 
} 

 

// Driver code 
int main() 
{ 
	int keys[] = {10,20,30,40}; 
	int freq[] = {4,2,6,3}; 
	int n = sizeof(keys)/sizeof(keys[0]); 
	cout << "Cost of Optimal BST is \n" << optimalSearchTree(keys, freq, n); 
	return 0; 
} 