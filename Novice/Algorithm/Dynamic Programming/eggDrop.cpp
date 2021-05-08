/*Egg Drop Puzzle
   To find minimum number of trials to find pivotal floor.
*/
/*If Number of floors are 0 or 1. Then total no of trials 
is equal to no of floors.
If there is only one egg no of trial is equal to number of 
floors in worst case*/

#include<bits/stdc++.h> 
using namespace std; 

int eggDrop(int n, int k) 
{ 
    if (k == 1 || k == 0) 
        return k; 
  
    if (n == 1) 
        return k; 
  
    int minimum = INT_MAX, res; 
  
    // Consider all droppings from 1st floor to kth floor and 
    // return the minimum of these values plus 1. 
    for (int x = 1; x <= k; x++) 
    { /*If egg breaks then our problem reduces we need to check with 
        1 less egg and and in lower floors.If egg doesnt break we need
        to check the above floors. So we subtract total floor - current floor.*/
        res = max(eggDrop(n-1, x-1), eggDrop(n, k-x)); 
        minimum=min(res,minimum); 
    } 
  
    return minimum + 1; //Add 1 to worst simulation.To get actual Drop.
}
int eggDropBu(int n, int k) 
{ 
    int eggTrial[n+1][k+1]; 
    int res; 
    int j, x; 
 
    for (int i = 1; i <= n; i++){
        /*If Number of floors are 0 or 1. Then total no of trials 
          is equal to no of floors.*/
        eggTrial[i][1] = 1; 
        eggTrial[i][0] = 0; 
    }
    /*For 1 egg the no of trial is equals to no of floors required.*/
    for(int j=1; j<=k;j++){
        eggTrial[1][j]=j;
    }
    //Fill Rest of the entries in table
    for (int i = 2; i <= n; i++) 
    { 
        for (int j = 2; j <= k; j++) 
        { 
            eggTrial[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) 
            { 
                res = 1 + max(eggTrial[i-1][x-1], eggTrial[i][j-x]); 
                if (res < eggTrial[i][j]) 
                    eggTrial[i][j] = res; 
            } 
        } 
    } 
    return eggTrial[n][k]; 
}  
int main() 
{ 
    int n = 2, k = 10; 
    cout << "Minimum number of trials in worst case with "
         << n << " eggs and " << k << " floors is " 
         << eggDrop(n, k) << endl; 
    cout << "Minimum number of trials in worst case with "
         << n << " eggs and " << k << " floors is " 
         << eggDropBu(n, k) << endl; 
     
    return 0; 
} 