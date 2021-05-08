// Count Inversions in an array
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
#include<iostream>        
using namespace std;
int merge(int *a,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=(mid+1);
    int k=s;
    int temp[10000];
    int cnt=0;
    while(i<=mid and j<=e){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }else{
            temp[k++]=a[j++];
            cnt+=mid-i+1;
        }
    }
    //fill the array if some elements are left in one of the arrays
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    
    //copy all the elements back to original array a 
    for(int i=s ;i<=e;i++){
        a[i]=temp[i];
    }
    return cnt;
}


int inversion_count(int *a,int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    //merge sort 
    int mid=(s+e)/2;
    int x=inversion_count(a,s,mid);
    int y=inversion_count(a,mid+1,e);
    int z=merge(a,s,e);//cross inversion
    return x+y+z;
}
int main()
{
    int arr[]={1,5,2,6,3,0};
    int n=sizeof(arr)/sizeof(int);
    cout<<inversion_count(arr,0,n-1)<<endl;
}