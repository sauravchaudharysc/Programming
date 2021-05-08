/*Mike loves hashing. He decides to create his own hashing technique, so he creates a Hash Function, given as :


int* hash_array(int A[], int n)
{
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

You are given an array A. You have to find the Mike's hashes for all the values that appears in this array.

Input Format
First line contains a single integer n. Next line contains n integers, denoting the elements of array, A.

Constraints
1<=N<=10^5 1<=A[i]<=10^9

Output Format
Print k lines, where k is the number of distinct integers in A. ith line contains integer whose hash value is (i-1).

Sample Input
4
1 2 1 3
Sample Output
2
1
3
Explanation
First iteration : hash[1] = 0. Second iteration : hash[2] = 0 + 1. Third iteration : hash[2] = hash[2] - 1 = 0, hash[1] = 1. Fourth iteration : hash[3] = 1 + 1 = 2.*/
#include <iostream>
#include<map>
#define ll long long int
using namespace std;
int main() {
    map<ll,ll> mp;
    map<ll,ll> ans;
    ll n;
    cin>>n;
    ll arr[n];
    ll val=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]=val++;
    }
    /*Uncomment it to know the logic.The map key represent the element of array
    and its value represent the index of last occurence of the element.
    for(auto it =mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<mp[it->second]<<endl;
    }*/
    
    /*Since map sorts according to key.So i make a secondary array and pass the mp value 
    which represent the index to sort it on the basis of occurence*/
    for(auto it =mp.begin();it!=mp.end();it++)
    {
        ans[it->second]=it->first;
    }
    for(auto it =ans.begin();it!=ans.end();it++)
    {
        cout<<it->second<<endl;
    }
}