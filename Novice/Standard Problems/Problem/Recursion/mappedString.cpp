/*We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.

Input Format
A single line contains a number.

Constraints
Number is less than 10^6

Output Format
Print all the possible strings in sorted order in different lines.

Sample Input
123
Sample Output
ABC
AW
LC
Explanation
'1' '2' '3' = ABC
'1' '23' = AW
'12' '3' = LC*/
#include<bits/stdc++.h>
using namespace std;

void mappedString(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch1=str[0];
    string ros=str.substr(1);
    int ch1_int = ch1-'0';
    ch1=ch1-'0'+'A'-1;
    mappedString(ros,ans+ch1);
    if(ros.length()>0){
        char ch2=str[1];
        int ch2_int = ch2-'0';
        int combined_num=ch1_int*10+ch2_int;
        if(combined_num<27){
            ch2 = combined_num+ 'A'-1;
            string ros2 = str.substr(2);
            mappedString(ros,ans+ch2);
        }
    }
}



int main(){
    string s;
    string ans="";
    cin>>s;
    mappedString(s,ans);
}