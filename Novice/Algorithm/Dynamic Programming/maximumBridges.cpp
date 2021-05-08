/*In maximumBridges problem we sort the southern co-ordinates so that they are arranged
in increasing order . Now we calculate the LIS in northern co-ordinates so we get the
number of bridges since the array of south is already sorted*/
#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
        int north;
        int south;
};
bool compare(Pair a,Pair b){
    if(a.south==b.south){
        return a.north<b.north;
    }
    return a.south<b.south;
}
int maximumBridges(Pair arr[],int n)
{
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    int best = 1;
    sort(arr,arr+n,compare);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j].north<=arr[i].north){
                int currLen=1+dp[j];
                dp[i]=max(dp[i],currLen);
            }
        }
      best=max(best,dp[i]);
    }
    return best;
}
int main()
{
    Pair arr[]={{5,6},{3,4},{10,1}};
    cout<<maximumBridges(arr,3);
}