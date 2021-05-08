//Binary Search Using Recursion
#include <stdio.h>
#define max 100
int binarysearch(int a[],int low,int high,int item);
int main()
{
    int a[max],n,item,i,index;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    int low=0,high=n-1;
    printf("Enter the %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the elements to search ");
    scanf("%d",&item);
    index=binarysearch(a,low,high,item);
    if(index!=-1)
    printf("The element is found at position %d and value is %d",index,a[index]);
    else
    printf("Not Found");
    
}
int binarysearch(int a[],int low,int high,int item)
{
    int mid;
    if(low<=high)
    {
    mid=(low+high)/2;
    if(a[mid]==item)
    return mid;
    else if(a[mid]>item)
    return binarysearch(a,low,mid-1,item);
    return binarysearch(a,mid+1,high,item);
    }
    return -1;
}
