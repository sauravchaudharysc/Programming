#include<bits/stdc++.h>
using namespace std;
string keycode[]={".","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printKeypad(string str,string ans)
{
	if(str.length()==0)
	{
	cout<<ans<<endl;
	return;
	}
	char ch=str[0];
	string ros=str.substr(1);
	string key=keycode[ch-'0'];
	for(int i=0;i<key.length();i++)
	{
		printKeypad(ros,ans+key[i]);
	}
}
int main()
{
	printKeypad("123","");
}