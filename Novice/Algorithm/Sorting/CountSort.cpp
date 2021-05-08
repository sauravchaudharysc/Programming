#include<bits/stdc++.h>
using namespace std;
void countSort(int a[],int n, int maximum)
{
    int count[maximum+1];
    int output[n];
    memset(count,0,sizeof(count));
    
    for(int i=0;i<n;i++){
        ++count[a[i]];
    }
    
    for(int i=1;i<=maximum;i++){
       count[i]+=count[i-1];
    }
    
    //If we start the loop from last it makes it stable
    for(int i=n;i>=0;i--){
       output[count[a[i]]-1]=a[i];
       --count[a[i]];
    }
    
    for(int i=0;i<n;i++){
        a[i]=output[i];
    }
    
}
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    //Try for this case 
    /*int a[]={1, 4, 1, 2, 7, 5, 2};8*/
    int a[]={142, 134, 14, 28, 75, 54, 22};
    int n=sizeof(a)/sizeof(a[0]);
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        maximum=max(maximum,a[i]);
    }
    countSort(a,n,maximum);
    printarr(a,n);
}