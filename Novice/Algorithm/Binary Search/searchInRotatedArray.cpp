#include<bits/stdc++.h>
using namespace std;
int find(int a[],int n,int key)
{
    int start =0;
    int end =n-1;
    while(start<=end)
    {
        //Compute mid
        int mid=(start+end)/2;
        if(a[mid]==key){
            return mid;
        }
        //Check if start is less than mid then left is sorted
        else if(a[start]<=a[mid]){
            //If key lies between start and mid
            if(a[start]<=key and key<=a[mid]){
                end=mid-1;
            }else{
            //Nor key lies beyond this mid    
                start=mid+1;
            }
        }else{ //here the right side is sorted
            //If keys lies between mid and end
            if(a[mid]<=key and key<=a[end]){
                start = mid+1;
            }else{
                //If the key doesnt lie in this range
                end = mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    int a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<find(a,n,key);
}