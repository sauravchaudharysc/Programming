/*Now moving to optimised approach,basically idea is to take jump only when its needed. 
The variable maxReach stores at all time the maximal reachable position in the array. 
Jump stores the amount of jumps necessary to reach that position. step stores the amount 
of steps we can still take (and is initialized with the amount of steps at the first array 
position)

During the iteration, the above values are updated as follows:

First we test whether we have reached the end of the array, in which case we just need to 
return the jump variable.

Next we update the maximal reachable position. This is equal to the maximum of maxReach 
and i+A[i] (the number of steps we can take from the current position).

We used up a step to get to the current index, so steps has to be decreased.

If no more steps are remaining (i.e. steps=0, then we must have used a jump. 
Therefore increase jump. Since we know that it is possible somehow to reach 
maxReach, we initialize the steps to the amount of steps to reach maxReach 
from position i.*/

#include<bits/stdc++.h>
using namespace std;

int MinJumpReq(vector<int> &a){
    int n=a.size();
    if(a[0]==0)return INT_MAX;
    int minJump=1;
    int maxReach=a[0],step=a[0];
    for(int i=1;i<n-1;i++){
        step--;
        maxReach=max(maxReach,i+a[i]);
        if(step==0){
            minJump++;
            if(maxReach<=i)return INT_MAX;
            step=maxReach-i;
        }
    }
    return minJump;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<MinJumpReq(a)<<"\n";
    }
}

