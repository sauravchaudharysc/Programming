//Minimum number of squares whose sum is equal to a given number.
#include<bits/stdc++.h>
using namespace std;
int perfectSquare(int n)
{
	if(n<=0)
	{
		return 0;
	}
	else
	{
		int min_Value=INT_MAX;
		int square=1;
		for(int i=1;square<=n;i++)
		{
			min_Value=min(min_Value,perfectSquare(n-square)+1);
			square=i*i;
		}
		return min_Value;
	}
}
int main()
{
	cout<<perfectSquare(5);
}