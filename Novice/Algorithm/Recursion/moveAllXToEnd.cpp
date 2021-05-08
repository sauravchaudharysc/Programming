#include<bits/stdc++.h>
using namespace std;
string moveAllXtoEnd(string str)
{
    if(str.length()==0)
    {
        return "";
    }
    else
    {
        char ch=str[0];
        string ros=str.substr(1);
        string recursionresult=moveAllXtoEnd(ros);
        if(ch=='x')
        {
            return recursionresult+ch;
        }
        else
        {
            return ch+recursionresult;
        }
    }
}

int main()
{
    cout<<moveAllXtoEnd("xxxpixxpi");
}