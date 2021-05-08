#include<bits/stdc++.h>
using namespace std;
int i=0;
void printSubsequences(string str,string ans){
    if(str.length()==0){
        i++;
        cout<<ans<<" ";
        return;
    }
    char ch = str[0];
    string ros = str.substr(1);
    printSubsequences(ros,ans);
    printSubsequences(ros,ans+ch);
}
int main()
{
    string str;
    string ans="";
    cin>>str;
    printSubsequences(str,ans);
    cout<<endl<<i;
}