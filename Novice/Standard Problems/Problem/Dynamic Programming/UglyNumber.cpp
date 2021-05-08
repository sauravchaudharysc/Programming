/*You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n.

Constraints
1<=t<=100 1<=n<=10000

Output Format
Print nth number of that sequence.

Sample Input
2
7
10
Sample Output
8
12
Explanation
Sequence : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, …..*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getNthUglyNo(ll n) { 
		ll ugly[n]; // To store ugly numbers 
		ll i2 = 0, i3 = 0, i5 = 0; 
		ll next_multiple_of_2 = 2; 
		ll next_multiple_of_3 = 3; 
		ll next_multiple_of_5 = 5; 
		ll next_ugly_no = 1; 
		
		ugly[0] = 1; 
		
		for(ll i = 1; i < n; i++){ 
			//Choose the next element to be places in array
			next_ugly_no = min(next_multiple_of_2,min(next_multiple_of_3,next_multiple_of_5)); 
			ugly[i] = next_ugly_no; 
			
			if (next_ugly_no == next_multiple_of_2){ 
			i2 = ++i2; 
			next_multiple_of_2 = ugly[i2]*2; 
			} 
			if (next_ugly_no == next_multiple_of_3) { 
			i3 = ++i3; 
			next_multiple_of_3 = ugly[i3]*3; 
			} 
			if (next_ugly_no == next_multiple_of_5) { 
			i5 = ++i5; 
			next_multiple_of_5 = ugly[i5]*5; 
			} 
		} 
		return next_ugly_no; 
} 

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<getNthUglyNo(n)<<"\n";
    }
    return 0;
}

