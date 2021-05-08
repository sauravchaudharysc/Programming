#include<bits/stdc++.h>
using namespace std;

long long calculate(int a,int b)
{
	// initialize ans with 1
	long long ans = 1;
	while(b>0)
	{
	// check if last bit 1	
	  if(b&1){
	     ans = (ans * a);
	  }
	  
	// update value of a by a*a  
	  a = a*a;
	  
	// right shift b by 1  
	  b = b>>1;
	}
	
	return ans;
}

int main()
{
	int a,b;
	long long ans;
	cout<<"enter the value of a and b : ";
	cin>>a>>b;
	
	cout<<"a^b = "<<calculate(a,b)<<endl<<endl;
	return 0;
}
