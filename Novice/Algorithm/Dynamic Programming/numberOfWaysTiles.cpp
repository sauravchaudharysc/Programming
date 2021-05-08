// C++ implementation to count number of ways to 
// tile a floor of size n x m using 1 x m tiles 
#include <bits/stdc++.h> 

using namespace std; 

int countWays(int n, int m) 
{ 

	int count[n + 1]; 
	count[0] = 0; 

	for (int i = 1; i <= n; i++) { 
	/*Here i can be assumed as length. Then the no of tile to be placed
	will be always when 1 until i is less than breadth.And will be 2 when equal.
	Rest is caluclated by reccurence relation */
		if (i > m) 
			count[i] = count[i - 1] + count[i - m]; 

		// base cases 
		else if (i < m) 
			count[i] = 1; 

		// i = = m 
		else
			count[i] = 2; 
	} 

	return count[n]; 
} 

int main() 
{ 
	int n = 2, m = 3; 
	cout << "Number of ways = "<< countWays(n, m)<<endl;
} 