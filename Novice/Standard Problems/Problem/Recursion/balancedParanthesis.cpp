/*Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(()) */
#include<bits/stdc++.h>
using namespace std;
void printCombination(int n ,int i,int j,string ans)
{
    if(i==n && j==n){
        cout<<ans<<endl;
        return;
    }
    if(i<j){
        return;
    }
    if(i>n or j>n){
        return;
    }
    
    printCombination(n,i,j+1,ans+')');
    printCombination(n,i+1,j,ans+'(');
}
int main(){
    int n;
    cin>>n;
    int i=0;
    string ans="";
    printCombination(n,0,0,ans);
}