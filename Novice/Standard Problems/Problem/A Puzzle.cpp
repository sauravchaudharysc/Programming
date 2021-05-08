#include <stdio.h>
#include<stdlib.h>
#define N 3
char vis[98765432]={0};
int q[362999]={0};
int l,r;
int a[N][N];
int isprime(int x)
{
    if(x==2||x==3||x==5||x==7||x==11||x==13||x==17)
    return 1;
    return 0;
}
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
    return;
}
void check(int level)
{
    int t=0,i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
            t=t*10+a[i][j];
        }
    }
    if(vis[t/10]!=0)
    return ;
    vis[t/10]=level;
    q[r++]=t;
}
void solve()
{
    l=0;
    r=1;
    int i,j;
    int cur=123456789;
    vis[cur/10]=1;
    q[l]=cur;
    while(l<r)
    {
        cur=q[l];
        l++;
        int t=cur;
        for(i=2;i>=0;i--)
        {
            for(j=2;j>=0;j--)
            {
                a[i][j]=cur%10;
                cur=cur/10;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+1<3&&isprime(a[i][j]+a[i+1][j]))
                {
                    swap(&a[i][j],&a[i+1][j]);
                    check(vis[t/10]+1);
                 swap(&a[i][j],&a[i+1][j]);
                       
                }
                if(j+1<3&&isprime(a[i][j]+a[i][j+1]))
                {
                    swap(&a[i][j],&a[i][j+1]);
                    check(vis[t/10]+1);
                 swap(&a[i][j],&a[i][j+1]);
                       
                }
                
            }
        }
        
    }
}


int NumberOfSwapsForRoy(int matrix_rows,int matrix_columns,int **matrix)
{
 solve();  
     int ans=0,i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                ans=ans*10+matrix[i][j];
                
            }
        }
    return vis[ans/10]-1;
}