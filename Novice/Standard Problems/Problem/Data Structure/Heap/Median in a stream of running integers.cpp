/*You are given a running data stream of n integers. You read all integers from that running data stream and find effective median of elements read so far in efficient way. All numbers are unique in the datastream. Print only the integer part of the median.

Input Format
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data stream and next line contains n space separated integers.

Constraints
1 < t < 100
1< n < 10000

Output Format
Print the effective median of running data stream..

Sample Input
1
6
5 15 1 3 2 8
Sample Output
5 10 5 4 3 4
Explanation
Iteration 1 :
Array = {5}
Median = 5

Iteration 2 :
Array = {5,15}
Median = (5+15)/2 = 10

Iteration 3 :
Array = {1,5,15}
Median = 5

Iteration 4 :
Array = {1,3,5,15}
Median = (3+5)/2 = 4

Iteration 5 :
Array = {1,2,3,5,15}
Median = 3

Iteration 6 :
Array = {1,2,3,5,8,15}
Median = (3+5)/2 = 4

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long q;
    cin>>q;
    
    priority_queue<long,vector<long>,greater<long>>minHeap;
    
    priority_queue<long>maxHeap;
    while(q--){
        long n;
        cin>>n;
        long x,m;
        for(long i=0;i<n;i++){
            cin>>x;
            if(i==0){
                maxHeap.push(x);
                cout<<maxHeap.top()<<" ";
                m=maxHeap.top();
                continue;
            }
            if(maxHeap.size()>minHeap.size()){
                if(m>x){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }else{
                    minHeap.push(x);
                }
                 m=(minHeap.top()+maxHeap.top())/2;
                 cout<<m<<" ";
            }else if(maxHeap.size()<minHeap.size()){
                if(m<x){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }else{
                    maxHeap.push(x);
                }
                m=(minHeap.top()+maxHeap.top())/2;
                cout<<m<<" ";
            }else{
                if(m<x){
                    minHeap.push(x);
                    m=minHeap.top();
                    cout<<m<<" ";
                }else{
                    maxHeap.push(x);
                    m=maxHeap.top();
                    cout<<m<<" ";
                }
            }
        }
        cout<<endl;
    }
}