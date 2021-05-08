#include<stdio.h>
#define max 20
int linearsearch(int a[],int n,int item);
int main()
{
    int a[max],x,n,item,index;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[i]=x;
    }
    printf("Enter the elements to be searched \n");
    scanf("%d",&item);
    index=linearsearch(a,n,item);
    if(index==-1)
    {
        printf("Not Found");
        
    }
    else
    printf("Found at %d position",index);
}
int linearsearch(int a[],int n,int item)
{
        if(a[n-1]==item)
        return n-1;
        if(n<0)
        return -1;
        return linearsearch(a,n-1,item);
}
