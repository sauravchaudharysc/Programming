/*All unique combinations whose sum equals to K
Given an array arr[] of size N and an integer K. 
The task is to find all the unique combinations from the given array such that sum of the elements in each combiantion is equal to K.*/
#include<bits/stdc++.h>
using namespace std;

void uniqueCombination(int arr[],int si,int n,vector<int>&ans,int key,int sum){
    //If a unique combinations is found
    if(sum==key){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //For all other combinations
    for(int i=si;i<n;i++){
        //Check if the sum exceeds key element
        if(sum+arr[i]>key){
            return;    
        }
        //The check i>si confirms that the current index is greater than starting index
        if (arr[i] == arr[i - 1] and i > si) 
            continue; 
        ans.push_back(arr[i]);
        uniqueCombination(arr,i+1,n,ans,key,sum+arr[i]);
        //Remove element from the combination
        ans.pop_back();
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int key;
    cin>>key;
    vector<int>ans;
    uniqueCombination(arr,0,n,ans,key,0);
}