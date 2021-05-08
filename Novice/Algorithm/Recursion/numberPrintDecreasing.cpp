#include<bits/stdc++.h>
using namespace std;
void numberPrint(int n)
{
    if(n==0)     
    {
    return;
    }
    cout<<n<<" ";
    numberPrint(n-1);
}
int main()
{
    int n;
    cin>>n;
    numberPrint(n);
    
}