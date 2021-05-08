#include<bits/stdc++.h>
using namespace std;
void printSubsequences(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    else
    {
        char ch=str[0];
        string ros=str.substr(1);
        printSubsequences(ros,ans);
        printSubsequences(ros,ans+ch);
    }
}

int main()
{
    printSubsequences("abc","");
}