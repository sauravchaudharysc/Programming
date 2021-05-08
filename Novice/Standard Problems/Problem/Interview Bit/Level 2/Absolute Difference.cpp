#include<bits/stdc++.h>
using namespace std;

void maxArr(int A[],int n){
    int max1=INT_MIN,max2=INT_MIN;
    int min1=INT_MAX,min2=INT_MAX;
    
    for(int i=0;i<n;i++){
        //A[i]>A[j]
        max1=max(max1,A[i]+i);
        min1=min(min1,A[i]+i);
        max2=max(max2,A[i]-i);
        min2=min(min2,A[i]-i);
    }
    int ans=max(max1 - min1, max2 - min2);
    cout<<ans<<endl;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxArr(arr,n);
}