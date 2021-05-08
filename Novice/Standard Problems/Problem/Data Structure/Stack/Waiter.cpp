/*https://www.hackerrank.com/challenges/waiter/problem*/
#include<bits/stdc++.h>
using namespace std;

int arr[10005]={0};
int prime[1202];
void prime_Sieve(int arr[]){
    for(int i=3;i<10005;i=i+2){
        arr[i]=1;
    }
    for(int i=3;i<10005;i=i+2){
        if(arr[i]==1){
            for(int j=i*i;j<10005;j=j+i){
                arr[j]=0;
            }
        }
    }
    
    arr[2]=1;
    arr[1]=arr[0]=0;
    int count=0;
    for(int i=0;i<10005;i++){
        if(arr[i]){
            prime[count++]=i;
        }
    }
}
int main()
{
    int N,Q;
    cin>>N>>Q;
    prime_Sieve(arr);
    stack<int>S1,S2,S3;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        S1.push(x);
    }
    for(int i=0;i<Q;i++){
          if(S1.empty()){
            break;
        }
        int curr=prime[i];
        while(!S1.empty()){
            int ele=S1.top();
            S1.pop();
            if(ele%curr==0){
                S2.push(ele);
            }else{
                S3.push(ele);
            }
        }
        while(!S2.empty()){
            cout<<S2.top()<<endl;
            S2.pop();
        }
        S1=S3;
        while(!S3.empty()){
            S3.pop();
        }
    }
    
    while(!S1.empty()){
            cout<<S1.top()<<endl;
            S1.pop();
        }
}