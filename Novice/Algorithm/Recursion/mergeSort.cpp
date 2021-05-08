#include<bits/stdc++.h>
using namespace std;
void merger(int a[],int lb,int ub,int mid)
{
    int temp[ub-lb+1];
    int i,j,k;
    i=lb,j=mid+1,k=0;
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
     while(i<=mid)
    {
            temp[k++]=a[i++];    
        
    }
    while(j<=ub)
    {
            temp[k++]=a[j++];

    }
    for(i=lb;i<=ub;i++)
    {
        a[i]=temp[i-lb];
    }
}
void merge_Sort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        merge_Sort(a,lb,mid);
        merge_Sort(a,mid+1,ub);
        merger(a,lb,ub,mid);
    }
}
int main()
{
    int a[]={2,1,3,4,5,6,7,8,9,10};
    
    merge_Sort(a,0,9);
    
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}