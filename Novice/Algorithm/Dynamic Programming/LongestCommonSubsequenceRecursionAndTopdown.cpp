#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		return 0;
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

		return max(firstChoice,secondChoice);
	}
}

//Top Down Approach
const int MAX = 100;
int dp[MAX][MAX];
int lcsMemo(string s1,string s2){
	if(s1.length()==0 || s2.length()==0){
		dp[s1.length()][s2.length()] = 0;
		return 0;
	}

	if(dp[s1.length()][s2.length()]!=-1){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	int result;

	if(ch1==ch2){

		result  = 1 + lcsMemo(ros1,ros2);

	}else{

		int firstChoice = lcsMemo(s1,ros2);
		int secondChoice = lcsMemo(ros1,s2);

		result =  max(firstChoice,secondChoice);
	}
	return result;
}
int main()
{
    cout<<longestCommonSubsequence("ABCDGH","AEDFHR")<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<lcsMemo("ABCDGH","AEDFHR");
}