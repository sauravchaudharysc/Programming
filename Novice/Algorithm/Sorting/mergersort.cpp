//Pass n-1 in merge code 
#include<bits/stdc++.h>
using namespace std;

void merger(int arr[],int low,int mid,int high){
int k=0;
int i=low;
int j=mid+1;
int temp[high-low+1];
while(i<=mid and j<=high){
    if(arr[i]>arr[j]){
        temp[k++]=arr[j++];
    }else{
        temp[k++]=arr[i++];
    }
}

while(i<=mid){
    temp[k++]=arr[i++];
}
while(j<=high){
    temp[k++]=arr[j++];
}

for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
}
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merger(arr,low,mid,high);
    }
}


int main(){
    int arr[]={111,12,333,44,5,17,81,19,110};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}