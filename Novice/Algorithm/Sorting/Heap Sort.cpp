#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,largest,n);
    }
}



void heap_sort(int a[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(a,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        n--;
        heapify(a,0,n);
    }
}



int main()
{  
    int a[]={98,23,25,20,21,22,10,65,23,36,65,95,85,45,75,65,15,25,95,35,15,265,4};
    
    heap_sort(a,23);
    
    for(int i=0;i<23;i++)
    printf("%d ",a[i]);
   
    return 0;
}