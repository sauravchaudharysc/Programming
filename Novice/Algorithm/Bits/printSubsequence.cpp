#include<bits/stdc++.h>
using namespace std;

void printsubsequences(string str,int i,int n)
{
    int j=0;
    while(n>0)    
    {
        if(i&1){
            cout<<str[j];
        }
        j++;
        i=i>>1;
        n--;
    }
    cout<<endl;
}

void subsequences(string str)
{
    int n=str.length();
    for(int i=0;i<(1<<n);i++){
        printsubsequences(str,i,n);
    }
}
int main()
{
    string str;
    cin>>str;
    subsequences(str);
}