//Given an array of numbers, arrange them in a way that yields the largest value. 
//For example, if the given numbers are {54, 546, 548, 60}, the arrangement 
//6054854654 gives the largest value.

#include<bits/stdc++.h>
using namespace std;
bool compare(string X,string Y){
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY.compare(YX)>0?1:0;
}
void largestvalue(vector<string>s,int n)
{
	sort(s.begin(),s.end(),compare);
	for(int i=0;i<n;i++){
		cout<<s[i];
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string>s;
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			s.push_back(str);
		}
		largestvalue(s,n);
	}
}