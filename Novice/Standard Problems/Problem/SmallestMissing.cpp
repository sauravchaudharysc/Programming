/*Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

Examples
Input: {0, 1, 2, 6, 9}, n = 5, m = 10
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
Output: 8*/

#include<bits/stdc++.h>
using namespace std;
int findFirstMissing(int arr[],int start,int end){
    if(start>end){
        return end+1;
    }
    if(arr[start]!=start){
        return start;
    }
    int mid=(start+end)/2;
    if(arr[mid]==mid){
        return findFirstMissing(arr,mid+1,end);
    }
    
    return findFirstMissing(arr,start,mid);
}

int main(){
    int arr[]={0,1,2,3,4,5,6,7,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findFirstMissing(arr,0,n-1);
}