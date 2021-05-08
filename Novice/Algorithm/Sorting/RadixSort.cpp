#include<bits/stdc++.h>
using namespace std;
//In count sort modify arr[i] by arr[i]/exp)%10
void countSort(int arr[],int n,int exp){
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    
    //Stable sorting so need to do it from end
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
       for (int i = 0; i < n; i++) 
        arr[i]=output[i];
}

void radixsort(int arr[],int n)
{
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
       maximum=max(arr[i],maximum);
    }
    for(int exp=1; (maximum/exp)>0; exp*=10){
        countSort(arr,n,exp);
        
    }
}
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
 
int main()
{
    int arr[]={170, 45, 75, 90, 802, 24, 2, 66}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, n); 
    print(arr, n); 
}