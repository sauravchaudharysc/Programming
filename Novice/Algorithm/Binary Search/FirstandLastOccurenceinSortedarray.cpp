#include<bits/stdc++.h>
using namespace std;
int binarySearchFirstOccurence(int arr[],int n,int key)
{
    int low=0;
    int high=n;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            ans=mid;
            //Do not stop but explore the left part
            high=mid-1;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int binarySearchLastOccurence(int arr[],int n,int key)
{
    int low=0;
    int high=n;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            ans=mid;
            //Do not stop but explore the right part
            low=mid+1;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    int arr[]={1,2,3,4,5,5,5,6,7,8,9,10};
    int n=12;
        cout<<"Element Found at "<<binarySearchFirstOccurence(arr,n,5)<<endl;
        cout<<"Element Found at "<<binarySearchLastOccurence(arr,n,5)<<endl;
}