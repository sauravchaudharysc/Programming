#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int lb,int ub)
{
    int pivot=a[lb],i=lb,j=ub+1;
    do{
        do{
            i++;
        }while(i<=ub &&a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            a[i]^=a[j]^=a[i]^=a[j];
        }
    }while(i<j);
    if(lb!=j)
    {
            a[lb]^=a[j]^=a[lb]^=a[j];
    }
    return j;
}
int r_partition(int a[],int lb,int ub)
{
    int t= lb+(rand()%(ub-lb));
    swap(a[lb],a[t]);
    return partition(a,lb,ub);  //After swapping the first element call the partition.
}
void quick_Sort(int a[],int lb,int ub)
{
    int pivot;
    if(lb<ub)
    {
        pivot=r_partition(a,lb,ub); //Same as quick just swap the first element with any random element.
        quick_Sort(a,lb,pivot-1);
        quick_Sort(a,pivot+1,ub);
    }
}
int main()
{
    int a[]={2,1,3,4,5,6,7,8,9,10};
    
    quick_Sort(a,0,9);
    
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}