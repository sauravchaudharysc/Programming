#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
  cin>>n;
  int no;
  int count[64]={0};
  for(int i=0;i<n;i++){
     cin>>no;
     int j=0;
     while(no>0){
         if(no&1==1){
             count[j]+=1;
         }
         j++;
         no=no>>1;
     }
  }
  for(int i=0;i<64;i++){
      count[i]%=3;
  }
  int ans=0;
  for(int i=0;i<64;i++){
      ans+=count[i]*pow(2,i);
  }
  cout<<ans<<endl;
}