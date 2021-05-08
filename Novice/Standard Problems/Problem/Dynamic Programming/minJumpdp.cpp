/*You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

Constraints
1<=t<=50
1<=n<=1000
0<=A[i]<=100

Output Format
Print the minimum number of jumps.

Sample Input
1
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9*/

#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int minJumpToReachEnd(int arr[],int n)
{
    //Take two array to store the distance and minimum number of jumps
    int result[n];
    result[0]=0;
    for(int i=1;i<n;i++){
        result[i]=INF;   
    }
    int path[n];
    for(int i=1;i<n;i++){ 
        for(int j=0;j<i;j++){
           //Can I reach i from this j
           /*i.Yes :- Check number of steps from current j to required i. If its minimum then update it
	        ii.No :- Go to another j*/
            if(arr[j]+j>=i){
                if(result[i]>=result[j]+1){
                    result[i]=result[j]+1;
	     //Store the path from where you go minimum number of jumps  
                    path[i]=j;
                }
            }
        } 
    }
    return result[n-1];
}
int main()
{
 int t;
 cin>>t;
 while(t--){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i]; 
     }
     cout<<minJumpToReachEnd(arr,n)<<endl;     
 }

}