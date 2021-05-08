/*There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

Input Format
First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

Constraints
1<=N<=10^7
1<=k<=N
1 <= Ai <= 100000

Output Format
Space separated integers in a single line denoting strength of strongest fighters in the groups.

Sample Input
5
1 3 1 4 5
3
Sample Output
3 4 5
Explanation
First sub-group: 1 3 1 --> Max strength is 3
Second sub-group: 3 1 4 --> Max strength is 4
Third sub-group: 1 4 5 --> Max strength is 5
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    
    deque<int>Q;
    //First Process K Items Seperately 
    for(int i=0;i<k;i++){
        //The queue shouldnt be empty or contain smaller element.
        while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    } // We get the largest element from first K
    
    //Process the remaining element 
    for(int i=k;i<n;i++){
        cout<<a[Q.front()]<<" ";
        
        //Remove the element which are not part of current window 
        while(!Q.empty() && Q.front()<=i-k){
            Q.pop_front();
        }
        
        //Remove the element which arent useful in current window
         while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<a[Q.front()];
    
}