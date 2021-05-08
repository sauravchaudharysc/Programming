#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[],int size)
{
    if(size<=1)
     return 0;
    int ladder=arr[0];
    int stairs=arr[0];
    int jumps=1;
    for(int level=1;level<size;level++){
        if(level==size-1){
            return jumps;
        }
        /*We store the maximum ladder found in way so use it when the current ladder stairs are finished*/
       ladder=max(ladder,level+arr[level]);
       stairs--;
       /*If the current ladder is finished we use the longest ladder found till now*/
       if(stairs==0){
           jumps++;
           stairs=ladder-level; //Because we need to caluclate the no of steps remaining in that ladder.
       }
    }
    return jumps;
}
int main()
{
    int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}; 
    int size = sizeof(arr)/sizeof(int); 
    cout<<("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
}