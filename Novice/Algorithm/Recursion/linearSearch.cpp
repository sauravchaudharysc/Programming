#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int a[],int i,int n,int key)
{
    if(i<n)
    {
        if(a[i]==key)
        {
            return true;
        }
        linearSearch(a,i+1,n,key);
    }
    else
    {
    return false;
    }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    if(linearSearch(a,0,10,10))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}