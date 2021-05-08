#include<bits/stdc++.h>
using namespace std;
bool partitionEqualSubsetSum(int arr[],int n,int si,int sum,
int total)
{
	/*if the sum observed till yet is half 
	the total then it can be partition*/
    if(2*sum==total) 
    {
        return true;
    }
    if(si>=n || sum>total)
    {
        return false;
    }
    bool include=partitionEqualSubsetSum(arr,n,si+1,arr[si]+sum,total);
    bool exclude=partitionEqualSubsetSum(arr,n,si+1,sum,total);
    return include||exclude;
}
bool isPossible(int arr[],int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    /*If Total sum is odd it cant be partitioned.*/
    if(total&1)
    {
        return false;       
    }
    return partitionEqualSubsetSum(arr,n,0,0,total);
}
int main()
{
    int arr[]={1,5,11,5};
    int n=4;
    if(isPossible(arr,n))
    	{
    		cout<<"TRUE";
    	}
    else
    {
    	cout<<"FALSE";
    }		
}