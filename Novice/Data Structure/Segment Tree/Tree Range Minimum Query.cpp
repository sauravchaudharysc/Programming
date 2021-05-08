// C++ program for range minimum 
// query using highgment tree 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to get minimum of two numbers 
int minVal(int x, int y) { return (x < y)? x: y; } 

// A utility function to get the 
// middle index from corner indexes. 
int getMid(int s, int e) { return s + (e -s)/2; } 

int RMQUtil(int *st, int low, int high, int qlow, int qhigh, int index) 
{ 
	if (qlow <= low && qhigh >= high) 
		return st[index]; 

	if (high < qlow || low > qhigh) 
		return INT_MAX; 

	int mid = getMid(low, high); 
	return minVal(RMQUtil(st, low, mid, qlow, qhigh, 2*index+1), 
				RMQUtil(st, mid+1, high, qlow, qhigh, 2*index+2)); 
} 

int RMQ(int *st, int n, int qlow, int qhigh) 
{ 
	// Check for erroneous input values 
	if (qlow < 0 || qhigh > n-1 || qlow > qhigh) 
	{ 
		cout<<"Invalid Input"; 
		return -1; 
	} 

	return RMQUtil(st, 0, 8-1, qlow, qhigh, 0); 
} 

//To Create segment Tree
int *constructST(int arr[], int n) 
{ 
    //To create a tree in power of 2
	int x = pow(2,(int)(ceil(log2(n)))); 
	//Total no of nodes
	int max_size = 2*x - 1;
	//Constructing a tree
	int *st = new int[max_size]; 
	//Initialise array with INT_MAX
	for( int i=0; i<max_size; i++) st[i] = INT_MAX;
	//To fill the leaf nodes
    for(int i=0; i<n; i++)  st[i+x-1] = arr[i];
    //To fill the internal nodes
    for(int i=x-2; i>=0; i--) st[i] = minVal(st[2*i + 1], st[2*i + 2]);
	return st; 
}

int main() 
{ 
	int arr[] = {-1, 3, 0, 1, 2, 4}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	// Build highgment tree from given array 
	int *st = constructST(arr, n); 

	int qlow = 3; // Starting index of query range 
	int qhigh = 5; // Ending index of query range 

	// Print minimum value in arr[qlow..qhigh] 
	cout<<"Minimum of values in range ["<<qlow<<", "<<qhigh<<"] "<< 
	"is = "<<RMQ(st, n, qlow, qhigh)<<endl; 

	return 0; 
} 