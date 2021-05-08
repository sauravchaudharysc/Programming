/*
Partition of a set into K subsets with equal sum
Given an integer array of N elements, the task is to divide this array into K non-empty subsets such that the sum of elements in every subset is same. All elements of this array should be part of exactly one partition.
Examples:

Input : arr = [2, 1, 4, 5, 6], K = 3
Output : Yes
we can divide above array into 3 parts with equal
sum as [[2, 4], [1, 5], [6]]

Input  : arr = [2, 1, 5, 5, 6], K = 3
Output : No
It is not possible to divide above array into 3
parts with equal sum
*/


#include<bits/stdc++.h>
using namespace std;


//A Recursive Function which makes an subset by choosing element from the array
bool isKSubsestPossiblerec(int arr[],int N,int taken[],int subset[],int subsetSum,int k,int currIdx,int j){
    if(subsetSum==subset[currIdx]){
        if(currIdx==k-2){
            return 1;
        }
     return isKSubsestPossiblerec(arr,N,taken,subset,subsetSum,k,currIdx+1,N);
    }
    for(int i=j;i>=0;i--){
        if(taken[i]){
            continue;
        }
        
        int sum = subset[currIdx]+arr[i];
        if(sum<=subsetSum){
            taken[i]=1;
            subset[currIdx]=sum;
            bool ans = isKSubsestPossiblerec(arr,N,taken,subset,subsetSum,k,currIdx,i);
            taken[i]=0;
            subset[currIdx]-=arr[i];
            if(ans){
                return true;
            }
        }
    }
    return false;
}

//Checks Inititally the three Condition Before Passing it to Recursive Function
/*
1.If k is 1 then whole array is the single subset.
2.If no of subsets is greater than it cant be formed
3.Is the total sum divisible by k or not.If yes then only it can form three equal subsets.*/
bool isKSubsestPossible(int arr[],int n,int k){
    if(k==1){
        return 1;
    }
    if(k>n){
        return 0;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%k!=0){
        return 0;
    }
    int subsetSum=(sum/k);
    int subset[k]={0};
    int taken[n]={0};
    subset[0]=arr[n-1];
    taken[n-1]=1;
    return isKSubsestPossiblerec(arr,n-1,taken,subset,subsetSum,k,0,n-1);
    
}


int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    if(isKSubsestPossible(arr,n,k)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}