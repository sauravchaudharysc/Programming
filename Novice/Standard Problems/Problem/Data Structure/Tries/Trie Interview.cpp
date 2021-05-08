/*This placement season , Avinash is preparing for his upcoming interviews in multinational companies . He is trying to solve a problem which was previously asked in many companies. There is an array named arr. He is supposed to find the maximum value of (arr[a] ^ arr[a + 1] ^ arr[a + 2] …….. arr[b]) + (arr[c] ^ arr[c + 1] ^ arr[c + 2] …….. arr[d]) where 1 <= a <= b <= c <= d <= N , where N is the size of the array. Help him to find an optimal solution.

Input Format
First line of the test case will be the length of array N . Then on the next line you will be given N space separated integers.

Constraints
0 <= element of array <= 10^9 1 <= N <= 10^5

Output Format
The output contains a single integer denoting the maximum value of expression

Sample Input
4 
1 2 6 8
Sample Output
17
Explanation
Here in the given a=1, b= 2, c= 3, d=4 , so (1 ^ 2) + (6 ^ 8) = 3 + 14 = 17.*/

/*We need to get two subarrays after xoring and sum them such that their 
sum is maximum.

We will calculate the MaxXor from right to left and store it in a array.
We will calculate the MaxXor from left to i and we will get max from 
i to R using the value stored in array.
*/

#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
	int value; // Only used in leaf nodes
	TrieNode *arr[2];
};

// Utility function tp create a Trie node
TrieNode *newNode()
{
	TrieNode *temp = new TrieNode;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;

	// Start from the msb, insert all bits of
	// pre_xor into Trie
	for (int i = INT_SIZE - 1; i >= 0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1 << i);

		// Create a new node if needed
		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	// Store value at leaf node
	temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.

int maxYetXOR[100001] = {0};

int query(TrieNode *root, int pre_xor, int x)
{
	TrieNode *temp = root;
	for (int i = INT_SIZE - 1; i >= 0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1 << i);

		// Traverse Trie, first look for a
		// prefix that has opposite bit
		if (temp->arr[1 - val] != NULL)
			temp = temp->arr[1 - val];

		// If there is no prefix with opposite
		// bit, then look for same bit.
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}

	int x1 = pre_xor ^ (temp->value);
	int x2 = maxYetXOR[x+1];

	//cout << x1 << " " << x2 << endl;

	return x1 + x2;
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int InsertAllXORAndCheck(int arr[], int n)
{
	// Create a Trie and insert 0 into it
	TrieNode *root = newNode();
	insert(root, 0);

	// Initialize answer and xor of current prefix
	int pre_xor = 0;

	int result = 0;

	// Traverse all input array element
	for (int i = 0; i < n - 1; i++)
	{
		// update current prefix xor and insert it into Trie
		pre_xor = pre_xor ^ arr[i];
		insert(root, pre_xor);
		result = max(result, query(root, pre_xor, i));
	}
	return result;
}

int queryOne(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;
	for (int i = INT_SIZE - 1; i >= 0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1 << i);

		// Traverse Trie, first look for a
		// prefix that has opposite bit
		if (temp->arr[1 - val] != NULL)
			temp = temp->arr[1 - val];

		// If there is no prefix with opposite
		// bit, then look for same bit.
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	int x1 = pre_xor ^ (temp->value);
	return x1;
}

void calcMaxYetXOR(int arr[], int n) {
	TrieNode *root = newNode();
	insert(root, 0);
	int pre_xor = 0;
	for (int i = n-1; i>= 0; i--)
	{
		pre_xor = pre_xor ^ arr[i];
		insert(root, pre_xor);
		if(i == n-1) {
			maxYetXOR[i] = pre_xor;
		}else {
			maxYetXOR[i] = max(maxYetXOR[i+1], queryOne(root, pre_xor));
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
		//Maximum xor value from right to left
	calcMaxYetXOR(arr, n);
	cout << InsertAllXORAndCheck(arr, n);
	return 0;
}