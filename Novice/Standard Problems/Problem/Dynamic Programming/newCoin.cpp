/*Anjali introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13

If the n is very large then we solve it simply by recursion. See the code
*/

#include<bits/stdc++.h>
using namespace std;

long long int dp[1000000];

long long int coins(long long int n){
	if(n<=1000000 && dp[n] != -1)
		return dp[n];
	//base  case
	if(n <= 11){
		dp[n] = n;
		return dp[n];
	}
	long long ans = max(n,coins(n/2)+coins(n/3)+coins(n/4));
	if(n <= 1000000)
		dp[n] = ans;//memoize the answer
	return ans;
}
int main(){
	long long int n,i;
	
	for(i=0;i<=1000000;i++){
		dp[i] = -1;
	}
	
	cin>>n;
	cout<<coins(n);
	
	return 0;
}