
/*You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.

Input Format
First line contains integer t as number of test cases.
Next t lines contains one balanced expression each.

Constraints
1 < t < 100
1< expression < 100

Output Format
Print "Duplicate" if the expression has any redundancy. Else print "Not Duplicates".

Sample Input
2
(((a+(b))+(c+d)))
((a+(b))+(c+d))
Sample Output
Duplicate
Not Duplicates
Explanation
For 1st test case : The subexpression "a+(b)" is surrounded by two pairs of brackets.*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        stack<int>st;
        string s;
        cin>>s;
        int flag=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='a' || s[i]=='b' ){
                st.push(s[i]);
            }else if(s[i]==')'){
                char ch=st.top();
                if(ch=='('){
                    flag=0;
                    break;
                }
                st.pop();
                ch=st.top();
                while(st.top()!='('){
                    st.pop();    
                }
                st.pop();
            }
            
        }
        if(flag==1 && st.empty()){
            cout<<"Not Duplicates"<<endl;
        }else{
            cout<<"Duplicate"<<endl;
        }
    }
    
}