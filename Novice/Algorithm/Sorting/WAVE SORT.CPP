//Wave Short 
//Big-Small-Big-Small
//Sort and swap the alternate element. O(nlogn)
//Better Approach
/*
For first we check with next. And last we check with second last
Except for the first and last we check both left and right. Are they greater if yes
then its ok. Nor swap.*/

#include<iostream>
using namespace std;
int main(){
    int a[]={1,3,4,2,7,8};
    //Sort the array in wave form
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i+=2){
        //prev element
        if(i!=0 and a[i]<a[i-1]){
            swap(a[i],a[i-1]);
        }
        //next element
        if(i!=(n-1) and a[i]<a[i+1]){
            swap(a[i],a[i+1]); 
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}