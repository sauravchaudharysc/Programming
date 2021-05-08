#include<bits/stdc++.h>
using namespace std;
void printPermutations(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++){
		char ch = str[i];

		string ros = str.substr(0,i) + str.substr(i+1);
		printPermutations(ros,ans+ch);
	}
}
int main()
{
    string str;
    string ans="";
    cin>>str;
    printPermutations(str,ans);
}