/*
Suraj recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Suraj wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Suraj bhaiya it is now your job to help him out :)

Input Format
First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.

Constraints
T <= 10000

It is guaranteed that the answer does not exceed 10^6.

Output Format
Print the minimum cost that needs to be paid.

Sample Input
2
5
1

Sample Output
11
2

Explanation
In the first case there are 5 primes upto 11(2,3,5,7,11).

Algorithm.
1. Use Sieve to caluclate prime number. 
2. Make a Cumulative sum array. 
3. Use binary search first occurence or lower bound of stl to find the occurence and print that index.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll prime[10000001]={0};
ll cumsum[10000001]={0};


void prime_sieve(ll prime[],int n){
    //Mark all odd number as prime 
    for(int i=3;i<=n;i=i+2){
        prime[i]=1;
    }
    //Current index is 1 then it is prime
    for(ll i=3;i<=n;i++){
        if(prime[i]==1){
            //All multiples of it is not prime
            for(ll j=i*i;j<=n;j=j+i){
                prime[j]=0;    
            }
        }
    }
    prime[2]=1;
    prime[1]=prime[0]=0;
}

int first(ll arr[], ll low, ll high, int x, ll n) 
{ 
    if(high >= low) 
    { 
        int mid = low + (high - low)/2; 
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x) 
            return mid; 
        else if(x > arr[mid]) 
            return first(arr, (mid + 1), high, x, n); 
        else
            return first(arr, low, (mid -1), x, n); 
    } 
    return -1; 
} 

int main()
{
    prime_sieve(prime,10000000);
    cumsum[0]=cumsum[1]=0;
    for(ll i=2;i<=10000000;i++){
         cumsum[i]=cumsum[i-1]+prime[i];   
        }
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        ll x = first(cumsum,0,10000000,n,10000000);
        cout<<x<<endl;
    }    
}