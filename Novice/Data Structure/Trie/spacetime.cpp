#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<(n-i);j++){
            a[j]^=a[j+1]^=a[j]^=a[j+1];
        }
    }
}

int main(){
    int n;
    int a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        a[i]=n-i;
    }
    time_t start=clock();
    bubble_sort(a,n);
    time_t end=clock();
    cout<<"Bubble sort took "<<end-start<<endl;
    for(int i=0;i<n;i++){
        a[i]=n-i;
    }
    start=clock();
    sort(a,a+n);
    end=clock();
    cout<<"Merge sort "<<end-start<<endl;
    return 0;
}