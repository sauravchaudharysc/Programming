/*Algorithm The steps to solve this problem:

Scan from right to left, find the first element that is less than its previous one.

4 5 6 3 2 1 
  |
  p
Scan from right to left, find the first element that is greater than p.

4 5 6 3 2 1 
    |
    q
Swap p and q

4 5 6 3 2 1 
swap
4 6 5 3 2 1 
Reverse elements [p+1, nums.length]

4 6 1 2 3 5 */



#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse(int arr[],int si,int ei){
    while(si<ei){
        int temp=arr[si];
        arr[si]=arr[ei];
        arr[ei]=temp;
        si++;
        ei--;
    }
}
void nextPermutation(int arr[])
{
    int n=arr.size();
    if(n<2){
        return;
    }
    int p=0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            p=i;
            break;
        }
    }
    int q=0;
    for(int i=n-1;i>p;i--){
        if(arr[i]>arr[p]){
            q=i;
            break;
        }
    }
    if (p == 0 && q == 0) {
            reverse(arr, 0, n - 1);
            print(arr,n);
            return;
    }
    
    //Swap p and q 
    arr[p]^=arr[q]^=arr[p]^=arr[q];
    
    //Reverese p+1 length
    if(p<n-1){
        reverse(arr,p+1,n-1);
        print(arr,n);
        return;
    }
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        nextPermutation(arr);
    }
    
}
