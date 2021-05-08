/*Sum of bit differences among all pairs
Given an integer array of n integers, find sum of bit differences in all pairs that can be
formed from array elements. 
Bit difference of a pair (x, y) is count of different bits at same positions in binary 
representations of x and y.

Examples :

Input: arr[] = {1, 2}
Output: 4
All pairs in array are (1, 1), (1, 2)
                       (2, 1), (2, 2)
Sum of bit differences = 0 + 2 +
                         2 + 0
                      = 4

Input:  arr[] = {1, 3, 5}
Output: 8
All pairs in array are (1, 1), (1, 3), (1, 5)
                       (3, 1), (3, 3) (3, 5),
                       (5, 1), (5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0 
                       = 8
*/
#include<bits/stdc++.h>
using namespace std;
#define mof 1000000007
int sumOfBitDifferences(int A[],int n){
    int ans=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if((A[j]&(1<<i))){
                count++;
            }
        }
        ans+=(count*(n-count)*2)%mof;
    }
    return ans%mof;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sumOfBitDifferences(arr,n)<<endl;
    }
    
}