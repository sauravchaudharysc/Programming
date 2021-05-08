/*Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray of 1s.

Input Format
First Line : n, size of array and k Second Line : n space separated numbers (0s or 1s)

Constraints
n <= 10^5 0 <= k <= n

Output Format
First Line : Size of subarray Second Line : Array after flipping k 0s

Sample Input
10 2
1 0 0 1 0 1 0 1 0 1
Sample Output
5
1 0 0 1 1 1 1 1 0 1*/
/*We iterate the array using two pointer.
Here l means left and i is the right pointer.

For each zero discovered we make it 1 and decrease the swap by 1.
When count reaches greater than k we shift the window and decrease the size of count until zero encountered.

We store the index of start for maximum window and print the array.*/

#include <iostream>
#define ll long long int
using namespace std;

void longestSubSeg(int *a,int n,int k) {
    int l=0,start=0;
    int maxlen=0,len=0;
    int cnt0=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
            cnt0++;
        while(cnt0>k){
            if(a[l]==0)
                cnt0--;
            l++;
        }
        len=i-l+1;
        if(maxlen<(len)){
            start=l;
            maxlen = len;
        }
    }
    cout<<maxlen<<endl;
    cnt0=0;
    for(int i=0;i<n;i++){
        if(i>=start && cnt0<k && a[i]==0){
            cout<<"1"<<" ";
            cnt0++;
        }
        else{
            cout<<a[i]<<" ";  
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    longestSubSeg(a, n, k);
    return 0;
}