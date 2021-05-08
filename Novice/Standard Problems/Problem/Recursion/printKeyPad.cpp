/*You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.

*/
#include<bits/stdc++.h>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void mobileKeypad(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    //To get the index of the table
    int ch1_int=str[0]-'0';
    string key=table[ch1_int];
    string ros=str.substr(1);
    for(int i=0;i<key.length();i++){
        mobileKeypad(ros,ans+key[i]);
    }
}

int main(){
    string str;
    cin>>str;
    string ans="";
    mobileKeypad(str,ans);
}
