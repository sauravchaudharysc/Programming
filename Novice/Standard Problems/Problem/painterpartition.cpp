/*This problems consider a sorted array input nor for unsorted we use a max function to 
find minimum value*/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long int arr[],long long int N,long long int K,long long int Time){
    long long int painter=1;
    long long int sum=0;
    for(long long int i=0;i<N;i++){
        if(sum>Time){
            sum=arr[i];
            painter++;
            if(painter>K){
                return false;
            }
        }else{
            sum+=arr[i];
        }
    }
    return true;
}
/*The Time required can be calculated using binary search becauase the minimum
time to paint the board will be maximum cost of painting the board among all.
The maximum time will be the sum of total time of all the boards.*/
void timeRequired(long long int arr[],long long int N,long long int K,long long int T){
    long long int low,high;
    low = arr[N-1]*T;
    for(long long int i=0;i<N;i++){
        high+=arr[i]*T;
    }
       long long int ans=INT_MAX;
    while(low<high){
        long long int mid=((high+low)/2);
        if(isPossible(arr,N,K,mid)){
            ans=min(ans,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    long long int N,K,T;
    cin>>N>>K>>T;
    long long int*arr=new long long int[N];
    for(long long int i=0; i<N; i++){
        cin>>arr[i];
    }
    timeRequired(arr,N,K,T);
}