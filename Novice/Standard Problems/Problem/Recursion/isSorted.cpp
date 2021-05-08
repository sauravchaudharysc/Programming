#include<bits/stdc++.h>
using namespace std;
bool sorted(int arr[],int i,int n){
    if(i==n){
        return true;
    }
    if(arr[i]>=arr[i-1]){
        return sorted(arr,i+1,n);
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(sorted(arr,1,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}