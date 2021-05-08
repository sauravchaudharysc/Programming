/*Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

Input Format
First line contains first string . Second line contains second string. Third line contains the third string.

Constraints
The length of all strings is |s|< 200

Output Format
Output an integer denoting the length of longest common subsequence of above three strings.

Sample Input
GHQWNV
SJNSDGH
CPGMAH
Sample Output
2
Explanation
"GH" is the longest common subsequence
*/

#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2,string s3){
    int length1=s1.length();
    int length2=s2.length();
    int length3=s3.length();
    int dp[length1+1][length2+1][length3+1];
    /*
    We cant use this to initialize zero
    for(int i=0;i<=length1;i++) dp[i][0][0]=0;
    for(int j=0;j<=length2;j++) dp[0][j][0]=0;
    for(int k=0;k<=length3;k++) dp[0][0][k]=0;*/
    
    for(int i=0;i<=length1;i++){
        for(int j=0;j<=length2;j++){
            for(int k=0;k<=length3;k++){
                if(i==0 || j==0 || k==0){
                    dp[i][j][k]=0;
                }else if(s1[i-1] == s2[j-1] && s1[i-1]==s3[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }else{
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));   
                }
            }   
        }
    }
    return dp[length1][length2][length3];
    
}

int main(){
    string s1;
    string s2;
    string s3;
    cin>>s1>>s2>>s3;
    cout<<lcs(s1,s2,s3)<<endl;
}