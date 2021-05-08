#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int key)
{
    int low=0;
    int high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return 1;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    if(binarySearch(arr,n,5)){
        cout<<"Element Found"<<endl;
    }else{
        cout<<"Element not Found"<<endl;
    }
}