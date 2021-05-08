#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int a[],int low,int high,int key)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            return true;
        }
        else if(a[mid]<key)
        {
            binarySearch(a,mid+1,high,key);
        }
        
        else
        {
            binarySearch(a,low,mid-1,key);
        }
    }
    return false;
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    if(binarySearch(a,0,9,15))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}