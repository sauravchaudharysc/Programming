/*You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

Input Format
First line contains number of test cases, T. Next T lines contains integers, n and k.

Constraints
1<=T<=10 1<=N<=10^15 1<=K<=10^4

Output Format
Output the integer x

Sample Input
2
10000 1
1000000000000000 10
Sample Output
10000
31
Explanation
For the first test case, for x=10000, 10000^1=10000=n*/
/*We will aplly binary search in this problem. 
For every possible mid obtained by using binary search we will check of it is the best suitable candidate or 
not for becoming the Kth root and then we reduce the search space of the binary search according to the mid value. 
If mid^k is greater than N then we will find the best suitable value from left to mid-1 otherwise we will find much larger value by finding it from mid+1 to right.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }
        long long l=1,r=1000000,mid;
        while(l<r)
        {
            mid=l+r+1>>1;
            bool flag=1;
            long long tmp=1;
            for(int i=1;i<=k;i++)
            {
                tmp*=mid;
                if(tmp>n)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                l=mid;
            else
                r=mid-1;
        }
        cout<<r<<endl;
    }
}    