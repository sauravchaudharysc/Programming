#include <iostream>
#include <string>
using namespace std;

int minPartition(int S[], int n, int S1, int S2)
{
	// base case
	if (n < 0)
		return abs(S1 - S2);

	int inc = minPartition(S, n - 1, S1 + S[n], S2);
    int exc = minPartition(S, n - 1, S1, S2 + S[n]);
	return min (inc, exc);
}

int main()
{
	int S[] = { 10, 20, 15, 5, 25};
	int soln[5];

	int n = sizeof(S) / sizeof(S[0]);

	cout << "The minimum difference is " << minPartition(S, n - 1, 0, 0);

	return 0;
}