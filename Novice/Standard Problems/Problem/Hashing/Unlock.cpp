
/*Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;
    unordered_map<int,int>hash;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        /*Here we make a hash table where the key represent the element and 
        the value represent the index of the element in array.*/
        hash[x]=i;
    }
    
    //Main function
    /*The number will be maximum if the begining numbers are maximum and the number
    in n will be from 1 to n.We will try to put the maximum number as before as possible*/
    for(int i=0;i<n && k>0;i++){
      int x=n-i;
      //Is the number present at it spot or not.If present then check for next position
      if(v[i]==x){
        continue;  
      }
      //Get the current max-element index
      int index=hash[x];
      //Replace the current element index with max-element index
      hash[v[i]]=index;
      //Max element index is changed to current element
      hash[x]=i;
      
      //Swap the current element and the max element
      swap(v[i],v[index]);
      k--;
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    return 0;
}