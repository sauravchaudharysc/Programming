/*Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (according to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency. If frequency of two numbers are same then print them in increasing order.

Input Format
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the array and next line contains n space separated integers.

Constraints
1 < t < 100 1< n < 100000

Output Format
Print top k running stream.

Sample Input
1
5 2
5 1 3 5 2
Sample Output
5 1 5 1 3 5 1 5 1*/
#include<bits/stdc++.h>
using namespace std;

void kTop(int a[],int n,int k){
    
    //Initialise an vector of k+1 to store elements
    vector<int> top(k + 1);
    
    //An map to keep the track of frequency of each elements
    map<int, int> freq; 
    
    //Iterate the whole given array 
    for(int m=0;m<n;m++){
        //Increase the frequency of each element 
        freq[a[m]]++; 
        
        //Store the element at end of vector 
        top[k] = a[m];
        
        //Search for it address 
    	auto it = find(top.begin(), top.end() - 1, a[m]);
    	
    	//Now align the element in correct position in vector using frequency or ascending order
    	for(int i = distance(top.begin(), it) - 1; i >= 0; --i){
    	    //Compare the frequency if higher than swap it to starting
    	    if (freq[top[i]] < freq[top[i + 1]]){
    	        swap(top[i], top[i + 1]); 
    	    }
    	    
    	    //If frequency is same then arrange the element in ascending order
    	    else if((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1])){
    	        swap(top[i], top[i + 1]);   
    	    }else{
    	        break;
    	    }
    	}
    	// print top k elements 
		for (int i = 0; i < k && top[i] != 0; ++i) 
			cout << top[i] << ' '; 
	} 
	cout << endl; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        kTop(arr,n,k);
    }
}