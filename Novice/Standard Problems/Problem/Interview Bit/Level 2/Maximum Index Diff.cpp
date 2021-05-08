#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int A[],int n){
    //Stores the smallest left element
    int *left=new int[n];
    //Stores the largest right element
    int *right=new int[n];
    /*If we get an element larger than the element on left side of array 
    We dont need to consider it because this wont give us the maximum answer*/
    left[0]=A[0];
    for(int i=1;i<n;i++){
        left[i]=min(left[i-1],A[i]);
    }
    
    /*If we get an element smaller than the element on right side of array 
    We dont need to consider it because this wont give us the maximum answer*/
    right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],A[i]);
    }
    
    /*Traverse both arrays 
        One from left and another from right and compare them.
        
        Find max j-i when left[i]<right[j]
    */
    int i=0,j=0,maxDiff=-1;
    while(j<n && i<n){
        if(left[i]<right[j]){
            maxDiff=max(maxDiff,j-i);
            j++;
        }else{
            i++;
        }
    } 
    return maxDiff;
}
int main(){
     int arr[] = {9, 2, 3, 4, 5,6, 7, 8, 18, 0};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    int maxDiff = maxIndexDiff(arr, n);  
    cout << maxDiff;  
    return 0;  
}