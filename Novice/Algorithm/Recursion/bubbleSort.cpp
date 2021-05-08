#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n,int j)
{
    if(n==1)
    {
        return;
    }
    if(j==n-1)
    {
        return bubble_sort(a,n-1,0);
    }
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }    
        return bubble_sort(a,n,j+1);
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[]={5,4,2,3,1};
    bubble_sort(a,5,0);
    print(a,5);
}