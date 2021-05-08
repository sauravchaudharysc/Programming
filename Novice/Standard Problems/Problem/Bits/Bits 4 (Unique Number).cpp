#include<bits/stdc++.h>
using namespace std;
void uniqueNumberPair(int arr[],int n){
    int xorPair=arr[0];
    for(int i=1;i<n;i++){
        xorPair^=arr[i];
    }
    int var= xorPair;
    int position=0;
    while(1){
        if(var & 1){
            break;
        }
        position++;
        var = var >>1;
    }
    int check= xorPair;
    for(int i=0;i<n;i++){
        int element = (arr[i] >> position);
        if(element&1){
            check = check^arr[i];
        }
    }
    if(check > (xorPair^check)){
        cout<<(xorPair^check)<<" "<<check<<endl;
    }else{
        cout<<check<<" "<<(xorPair^check)<<endl;
    }
    
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    uniqueNumberPair(arr,n);
}