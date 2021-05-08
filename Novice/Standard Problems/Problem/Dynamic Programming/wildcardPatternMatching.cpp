/*
Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

Input Format
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints
1<= n <= 1000
1<= sum <= 10^5
1<= Ai <=10^4

Output Format
Yes, if sum exist No, it sum does not exist

Sample Input
5 10
1 2 3 4 5
Sample Output
Yes

How to create array dynamically
    bool** dp = new bool*[n+1];
        for(int i=0;i<=n;i++)
         dp[i]=new bool[s+1];*/

#include<bits/stdc++.h>
using namespace std;
int wildCardPatternMatching(string str,string pat){
    int strlength=str.length();
    int patlength=pat.length();
    
    //Replace multiple * with single star
    int writeIndex=0;
    bool isFirst=true;
    for(int i=0;i<patlength;i++){
        if(pat[i]=='*'){
            if(isFirst){
                pat[writeIndex++]=pat[i];
                isFirst=false;
            }
        }else{
            pat[writeIndex++]=pat[i];
            isFirst=true;
        }
    }
    
    bool dp[strlength+1][writeIndex+1];
    
    for(int i=0;i<=strlength;i++){
        dp[i][0]=false;
    }    
    for(int i=0;i<=writeIndex;i++){
        dp[0][i]=false;
    }    
    //For null character at begining 
    dp[0][0]=true;
    
    //If there is '*' present at start of pattern
    if(writeIndex>0 && pat[0] =='*'){
        dp[0][1]=true;
    }
    
    for(int i=1;i<=strlength;i++){
        for(int j=1;j<=writeIndex;j++){
            if(str[i-1]==pat[j-1] || pat[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if(pat[j-1] == '*'){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }else{
                dp[i][j]=false;
            }
        }
    }
    return (dp[strlength][writeIndex]?1:0);
}

int main(){
    string str;
    string pat;
    cin>>str;
    cin>>pat;
    cout<<wildCardPatternMatching(str,pat)<<endl;
}