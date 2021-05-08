#include<bits/stdc++.h>
using namespace std;
void arraySum(int a[],int b[],int n,int m)
{
	vector<int>v;
	int i=n-1;
	int j=m-1;
	int carry=0;
	while(i>=0 || j>=0){
		int sum=carry;
		if(i>=0){
			sum+=a[i];
		}
		if(j>=0){
			sum+=b[j];
		}
		v.push_back(sum%10);
		carry=sum/10;
		i--;
		j--;
	}
	if(carry!=0){
		v.push_back(carry);
	}
	reverse(v.begin(),v.end());
	for(auto i:v){
		cout<<i<<", ";
	}
	cout<<"END";
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	arraySum(a,b,n,m);
}