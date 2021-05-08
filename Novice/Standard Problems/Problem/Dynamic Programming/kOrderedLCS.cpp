/*Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

Input Format
The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. The third line contains M integers denoting the elements of the second sequence.

Constraints
1 <= N, M <= 2000
1 <= k <= 5
1 <= element in any sequence <= 109

Output Format
Print the answer in a new line.

Sample Input
5 5 1
1 2 3 4 5
5 3 1 4 2
Sample Output
3

Add these 
to diable c codes
ios_base::sync_with_stdio(0);
    to clear buffer in each input
    cin.tie(0);
    cin>>n>>m>>k;
    //The value must be between them
    assert(n >= 1 && n <= 2000);
    assert(m >= 1 && m <= 2000);
    assert(k >= 1 && k <= 5);
As mentioned in the problem statement, given problem is quite similar to the standard LCS problem. We can have following dp state DP(n,m,k) = denotes LCS for first n number of first array, first m numbers of second array when we are allowed to change at max k numbers in first array.

Recursion look like this ->
DP(n,m,k) = max(DP(n-1,m,k), DP(n, m-1, k), DP(n-1, m-1, k-1)+1), if arr[n]!=arr[m]
DP(n,m,k) = max(DP(n-1,m,k), DP(n, m-1, k), DP(n-1, m-1, k)+1), if arr[n]==arr[m]
The total number of distinct states, hence are = n * m * k
Time complexity = O(n * m * k)
*/
#include <iostream>
#define ll long long int
using namespace std;

ll dp[2005][2005][8];

ll korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
    if(n == i or m == j) {
        return 0;
    }
    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    ll res = 0;
    if(a[i] == b[j]) {
        res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k);
    } else {
        if(k>0) {
            res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k-1);
        }
        res = max(res, korderedLCS(a, b, n, m, i+1, j, k));
        res = max(res, korderedLCS(a, b, n, m, i, j+1, k));
    }
    dp[i][j][k] = res;
    return res;

}

int main(int argc, char const *argv[])
{

    int n, m, k;
    cin>>n>>m>>k;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    for(int i=0;i<2005;i++) {
        for(int j=0;j<2005;j++) {
            for(int m=0;m<8;m++) {
                dp[i][j][m] = -1;
            }
        }
    }
    cout<< korderedLCS(a, b, n, m, 0, 0, k);
    return 0;
}
