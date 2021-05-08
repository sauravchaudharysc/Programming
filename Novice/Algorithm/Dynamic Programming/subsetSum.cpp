#include <bits/stdc++.h> 
using namespace std;   
bool isSubsetSum(int input[], int n, int sum) 
{ 
    /*Row 1 all calumn except 0 is considered false as set is empty*/
    bool subset[n+1][sum+1]; 
   
    // Column 1:-If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<input[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         else{
           subset[i][j] = subset[i-1][j] || subset[i - 1][j-input[i-1]];  
         } 
            
       } 
     } 
     return subset[n][sum]; 
} 
   
int main() 
{ 
  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int n = sizeof(set)/sizeof(set[0]); 
  if (isSubsetSum(set, n, sum) == true) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
} 