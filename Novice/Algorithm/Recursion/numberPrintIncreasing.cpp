#include<bits/stdc++.h>
using namespace std;
void numberPrint(int n)
{
    if(n==0)     
    {
    return;
    }
    numberPrint(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    numberPrint(n);
    
}