/*O(N^2)Here we first sort the given array then we increase the dp array if last pair second
element is greater than next pair first element as done in LIS*/

#include<bits/stdc++.h>
using namespace std;
//Structure for a pair
class Pair
{
    public:
    int a;
    int b;
};
bool comparator(Pair p1,Pair p2)
{
    return (p1.a<p2.a);
}
int maximumLengthChain(Pair arr[],int n)
{
    sort(arr,arr+n,comparator);
    int *dp=new int[n];
    /*Each Pair is maximum so make each pair as length 1*/
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    int best=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].a>arr[j].b){
                int currLen = 1 + dp[j];
                dp[i] = max(dp[i],currLen);
            }
        }
     best=max(best,dp[i]);    
    }
    return best;
}
int main()
{
    Pair arr1[]={ {5,24}, {15,25}, {27,40}, {50,60}};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    Pair arr2[]={{6, 8}, {3, 4}};
    int n1 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<maximumLengthChain(arr1,n)<<endl;
    cout<<maximumLengthChain(arr2,n1);
}