#include<bits/stdc++.h>
using namespace std;
string replacePi(string str)
{
    if(str.length()==0)
    {
        return "";
    }
    else
    {
        char ch=str[0];
        string ros=str.substr(1);
        string recursionresult=replacePi(ros);
        if(ch=='p' && recursionresult[0]=='i')
        {
            return "3.14"+recursionresult.substr(1);
        }
        else
        {
            return ch+recursionresult;
        }
    }
}

int main()
{
    cout<<replacePi("xxxpixxpi");
}