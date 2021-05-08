#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n)
{
    int i,j,temp,flag=1;
    for(i=0;i<n-1&&flag==1;i++)
    {   
      flag=0;    
      for(j=0;j<n-1-i;j++)
      {  
        if(a[j+1]<a[j])
        {
            flag=1;
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
      }
    }  
}

int main()
{
    int i,j,a[50],n;
    cout<<"Enter the no of elements : - ";
    cin>>n;
    
    for(i=0;i<n;i++)
    cin>>a[i];
    
    bubble_sort(a,n);
    for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}



