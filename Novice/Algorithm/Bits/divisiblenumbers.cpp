//Calculate the number less than 1000 divisible by 2,3,5
#include<bits/stdc++.h>
using namespace std;

int printsubsequences(int str[],int i,int n)
{
    int j=0;
    int ans=1;
    while(n>0)    
    {
        if(i&1){
            ans*=str[j];
        }
        j++;
        i=i>>1;
        n--;
    }
    return ans;
}

void subsequences(int a[],int n,int sum)
{
    int total=0;
    for(int i=1;i<(1<<n);i++){
        int ans=printsubsequences(a,i,n);
        int count=i;
        int k=0;
        while(count>0){ 
            if(count&1){
                k++;} 
                count=count>>1;
        }
       if(k&1){
           total=total+(sum/ans);
       }else{
           total=total-(sum/ans);
       }
    }
    cout<<total;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    subsequences(a,n,999);
}