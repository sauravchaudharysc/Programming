#include<bits/stdc++.h> 
using namespace std; 
  
long long int countNonDecreasing(int n) 
{ 
    int N = 10; 
  
    long long count = 1; 
    for (int i=1; i<=n; i++) 
    { 
        count *= (N+i-1); 
        count /= i; 
    } 
  
    return count; 
} 
  
int main() 
{ 
    int n = 3; 
    cout << countNonDecreasing(n); 
    return 0; 
} 