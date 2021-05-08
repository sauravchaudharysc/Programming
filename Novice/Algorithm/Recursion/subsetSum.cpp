#include<bits/stdc++.h>
bool isPossible(int arr[],int sum,int si,int n)
{
    if(sum==0)
    {
        return true;
    }
    if(sum<0 || si>=n)
    {
        return false;
    }
    bool include=isPossible(arr,sum-arr[si],si+1,n);
    bool exclude=isPossible(arr,sum,si+1,n);
    return include || exclude;
    
}
bool subsetSum(int arr[],int sum,int n)
{
    return isPossible(arr,sum,0,n);
}
int main()
{
  int arr[] = {3, 34, 4, 12}; 
  int sum = 9; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  if (subsetSum(arr, sum,n) == true) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
}