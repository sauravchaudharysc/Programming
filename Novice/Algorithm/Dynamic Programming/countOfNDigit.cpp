//Count of n digit numbers whose sum of digits equals to given sum
#include<bits/stdc++.h> 
using namespace std; 
  
/*The first number is choosen already . The n is n-1 of initial n. 
We need to search numbers for n-1 digit to get the required sum.
So we subtract the sum from 0-10.And check at which condition the 
sum becomes 0 and add one to the answer for each such combination.*/
unsigned long long int countRec(int n, int sum) 
{ 
    // Base case 
    //This returns 1 only when no of digits becomes zero
    //and the sum has also become zero.
    if (n == 0) 
    return sum == 0; //returns 1 if sum==0 and 0 if not.
  
    if (sum == 0) 
    return 1; 
  
    unsigned long long int ans = 0; 
  
    for (int i=0; i<=9; i++) 
    if (sum-i >= 0) 
        ans += countRec(n-1, sum-i); 
  
    return ans; 
} 
 /*Unsigned long long int it used to make sure that the large value is also not
 altered and retuned correctly. Since it is of 32-bit. */
 /*Here we use the for loop from one to verify that the lead number isnt zero.
 In the iteration we see the number of ways the desired sum can be formed.By 
 subtracting each number choosen as first digit. The second number is searched in
 the above function. And if any number satisfies it count is incremented by 1. As 1
 get returned from above function.*/
unsigned long long int finalCount(int n, int sum) 
{ 
    // Initialize final answer 
    unsigned long long int ans = 0; 
  
    // Traverse through every digit from 1 to 
    // 9 and count numbers beginning with it 
    for (int i = 1; i <= 9; i++) 
    if (sum-i >= 0) 
        ans += countRec(n-1, sum-i); 
  
    return ans; 
} 
  
int main() 
{ 
    int n = 2, sum = 5; 
    cout << finalCount(n, sum); 
    return 0; 
} 