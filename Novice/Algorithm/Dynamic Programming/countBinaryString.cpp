#include <bits/stdc++.h> 
using namespace std; 
/*There are two strings one ending with 0 and one ending with 1.
the string ending with 0 can be appended with any string but 
one ending with 1 can only be appended with string ending in zero.
And also we can observe there is a pattern same as fibonnaci so we
can simply use fiboonaci bottom-up approach.*/  
int countBinaryStrings(int n) 
{ 
    int a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
} 
  
int main() 
{ 
    cout << countBinaryStrings(3) << endl; 
    return 0; 
}