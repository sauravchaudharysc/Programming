#include<bits/stdc++.h>
using namespace std;
int power(int n,int p)
{
    if(p==0)     //No of call stack is decided by the power of a number
    return 1;
    int result=power(n,p-1); //Make a call stack for each power until reduce to one
    return n*result; //Each call stack removal multiply it to the number
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<power(n,p);
}