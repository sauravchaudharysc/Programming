#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *a,int n) //since array base address is changed always. So pass by reference is unsigned
{
    if(n==1)  //An array with single element is always sorted.
    {
        return true;
    }
    if(a[0]<a[1] && isSorted(a+1,n-1)) //Enter only if the condition is satisified
    {
        return true;
    }
    return false;
}
int main()
{
    int a[]={1,2,3,4,5,6};
    if(isSorted(a,6))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"NO";
    }
}