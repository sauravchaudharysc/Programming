// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<iostream> 
#include<algorithm> 
using namespace std; 

struct Job 
{ 
char id;	 
int dead; 
int profit; 
}; 

bool comparison(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

void JobScheduling(Job arr[], int n) 
{ 
	
	int result[n]; // To store result (Sequence of jobs) 
	bool slot[n]; // To keep track of free time slots 

	for (int i=0; i<n; i++) 
		slot[i] = false; 

	for (int i=0; i<n; i++) { 
		for (int j=arr[i].dead-1; j>=0; j--) 
		{ 
			if (slot[j]==false) 
			{ 
				result[j] = i; 
				slot[j] = true; 
				break; 
			} 
		} 
	} 

	for (int i=0; i<n; i++) 
	if (slot[i]) 
		cout << arr[result[i]].id << " "; 
} 

int main() 
{ 
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
				{'d', 1, 25}, {'e', 3, 15}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	// Sort all jobs according to decreasing order of prfit 
	sort(arr, arr+n, comparison); 
	JobScheduling(arr, n); 
	return 0; 
} 
