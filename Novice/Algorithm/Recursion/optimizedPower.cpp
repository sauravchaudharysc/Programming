#include<bits/stdc++.h>
using namespace std;
int powerBetter(int n,int p)
{
    if(p==0)     //No of call stack is decided by the power of a number
    return 1;
    int halfresult=powerBetter(n,p/2); //Make a call stack for each power until reduce to power/2
    int fullresult=halfresult*halfresult;
    return p&1?fullresult*n:fullresult; //Each call stack removal multiply it to the number
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<powerBetter(n,p);
}