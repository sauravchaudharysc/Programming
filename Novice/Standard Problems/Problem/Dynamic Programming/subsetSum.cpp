/*Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

Input Format
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints
1<= n <= 1000
1<= sum <= 10^5
1<= Ai <=10^4

Output Format
Yes, if sum exist No, it sum does not exist

Sample Input
5 10
1 2 3 4 5
Sample Output
Yes*/

#include <iostream>
using namespace std;

bool subsetSum(int *arr, int n, int target) {
    bool **dp = new bool*[n+1];
    for(int i=0;i<=n;i++) {
        dp[i] = new bool[target+1];
    }
    dp[0][0] = true; // If sum is zero and no element is taken ans is true
    for(int i=1;i<=n;i++) { // If sum is zero ans is always true
        dp[i][0] = true;
    }
    for(int i=1;i<=target;i++) { // If no element is chosen and sum is not zero ans is false
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {
            if(j<arr[i-1]) {
                dp[i][j] = dp[i-1][j];
            } 
            if(j>=arr[i-1]) {
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][target];

}

int main()
{
    int n, target;
    cin>>n>>target;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    if(subsetSum(arr, n, target)) cout<<"Yes";
    else cout<<"No";
    return 0;
}