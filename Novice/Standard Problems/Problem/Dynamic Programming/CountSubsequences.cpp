/*Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input Format
First line of input contains an integer 't' denoting number of test cases.
Next t lines contain a string each.

Constraints
1<=t<=100
1<=length of s<=100000
s will contain upper letters only.

Output Format
For each test case ,print ans%1000000007 in a new line each ,where ans is the number of distinct subsequences.

Sample Input
2
AAA
ABCDEFG
Sample Output
4
128
Explanation
For "AAA" , the distinct subsequences that can be formed are { '', 'A' , 'AA' , 'AAA }. So we print 4 , no of distinct subsequences.*/

/*Explanation 
Consider the string S=“ABCB”

Let DP[i+1] = No. of distinct subsequences possible from S[0…i]

where DP[0] = 1, for empty subsequence { }

So, for the string "ABCDEFG"

For i=0;

Possible Subsequences: { },A

DP[1] = 2;

For i=1:

Possible Subsequences: { },A,B,AB

DP[2] = 4

for i=2:

Possible Subsequences: { },A,B,AB,C,AC,BC,ABC

DP[3] = 8

As we can observe,

DP[i] = DP[i-1]*2;

But till now, all characters were distinct.

Consider the next chracter ‘B’(Getting repeated),

Possible Subsequences:

{ },A,B,AB,C,AC,BC,ABC,B,AB,BB,ABB,CB,ACB,BCB,ABCB

DP[4] = 16

But here as we can see, (B,AB) are repeating (hence the subsequences are not distinct), Which we had obtained earlier by appending B at the end to ({ },A).

Hence the No. of repeating subsequences = DP[1] in this case.

Where, 1 is nothing but the previous occurence of the characer B. And we need to subtract the no. of repeating subsequences to get the result.

In this case,

DP[4] = 16 - 2 = 14

Hence DP[i] = DP[i-1]*2 - DP[Immediate previous occurence of character S[i-1]], if S[i-1] has occurred before.

Final Algo. obtained:

DP[0] = 1;

For i=0 to length(S)-1:

DP[i+1] = DP[i]*2;

if(previous[S[i]]>=0)

DP[i+1] = DP[i+1] - DP[previous[S[i]]];

previous[S[i]] = i;

Expected Output: DP[length(S)]

Note:

Previous[i] = Index of prev. occurence of i. If there is no previous occurence of i, then I have initialized it to some negative value.*/

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
const ll MAX_CHAR = 256; 
  
// Returns count of distinct sunsequences of str. 
ll countSub(string str) 
{ 
    // Create an array to store index 
    // of last 
    vector<ll> last(MAX_CHAR, -1); 
  
    // Length of input string 
    ll n = str.length(); 
  
    // dp[i] is going to store count of distinct subsequences of length i. 
    ll dp[n + 1]; 
  
    // Empty substring has only one subsequence 
    dp[0] = 1; 
  
    // Traverse through all lengths from 1 to n. 
    for (ll i = 1; i <= n; i++) { 
        // Number of subsequences with substring 
        // str[0..i-1] 
        dp[i] = 2 * dp[i - 1]; 
  
        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence. 
        if (last[str[i - 1]] != -1) 
            dp[i] = dp[i] - dp[last[str[i - 1]]]; 
  
        // Mark occurrence of current character 
        last[str[i - 1]] = (i - 1); 
    }
  
    return dp[n]; 
} 
  
int main() 
{ 
    ll t;
    cin>>t;
    while(t--){
     string s;
     cin>>s;
     cout << countSub(s)<<endl;     
    }
    
    return 0; 
} 