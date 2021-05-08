#include<bits/stdc++.h>
using namespace std;

//We find the pivotelement using binary search
/*The array is divided into halves and if the mid is greater than low
it means the left half is sorted so our search space decreases to mid+1 to high
and if not we check is the mid is less than high then right half is sorted.*/
int pivotelement(int arr[],int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid+1]<arr[mid]){
            return mid;
        }else if(arr[low]<=arr[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<pivotelement(arr,n);
}