#include <bits/stdc++.h>
using namespace std;


bool isKPartitionPossible(int [], int , int );

 
//  Driver code to test above methods
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	cout<<isKPartitionPossible(a, n, k)<<endl;
    }
}// } Driver Code Ends


bool isSubsetPossible(int arr[],int subsetSum,int subset[],int currIdx,int taken[],int k,int N){
    if(subset[currIdx]==subsetSum){
        if(currIdx==k-2){
            return 1;
        }
        return isSubsetPossible(arr,subsetSum,subset,currIdx+1,taken,k,N-1);
    }
    
    for(int i=N; i>=0;i--){
        //If Already Taken, continue 
        if(taken[i]){
            continue;
        }
        int temp = arr[i]+subset[currIdx];
        if(temp<=subsetSum){
            taken[i]=1;
            subset[currIdx]=temp;
            bool next = isSubsetPossible(arr,subsetSum,subset,currIdx,taken,k,i-1);
            taken[i]=0;
            subset[currIdx]-=arr[i];
            if(next){
                return 1;
            }
        }
    }
    return 0;
}
/*You are required to complete this method */
bool isKPartitionPossible(int arr[], int n, int k)
{
    if(n==k){
        return 1;
    }
    if(n<k){
        return 0;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%k!=0){
      return 0;   
    }
    int subsetSum=sum/k;
    int subset[k]={0};
    int taken[n]={0};
    subset[0]=arr[n-1];
    taken[n-1]=1;
    return isSubsetPossible(arr,subsetSum,subset,0,taken,k,n-1);
}