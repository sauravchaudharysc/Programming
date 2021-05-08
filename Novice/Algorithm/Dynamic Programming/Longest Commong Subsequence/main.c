#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int longestCommonSubsequence(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		return 0;
	}
    
    if(dp[s1.length()][s2.length()]!=-1){
		return dp[s1.length()][s2.length()];
	}
	
	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1);  //Removes First Letter
	string ros2 = s2.substr(1);  //Removes First Letter
    
	if(ch1==ch2){

		return 1 + longestCommonSubsequence(ros1,ros2);

	}else{

		int firstChoice = longestCommonSubsequence(s1,ros2); //First string ka pehla letter hatakar
		int secondChoice = longestCommonSubsequence(ros1,s2); //Second string ka pehla letter hatakar

		return dp[s1.length()][s2.length()]=max(firstChoice,secondChoice);
	}
}

int main()
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
   printf("%d",longestCommonSubsequence("ABCDGH","AEDFHR"));
}