Navneet likes to play with bits. One day Navneet  decides to assign a task to his student Sanya. You have help Sanya to complete this task. Task is as follows - Navneet gives Q queries each query containing two integers a and b. Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

Input Format
Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.

Constraints
Q,a,b are integers.

Output Format
Q lines, each containing an output for your query.

Sample Input
2
1 1
10 15
Sample Output
1
17

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x,y;
    for(int i=0; i<n;i++){
        cin>>x>>y;
    
    int count=0;
    for(int i=x;i<=y;i++){
        int num=i;
        while(num!=0){
          if(num&1){
            count++;
          } 
            num=num>>1;
        }
    }
    cout<<count<<endl;
    }
}