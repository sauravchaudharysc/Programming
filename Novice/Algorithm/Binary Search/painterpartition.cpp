//Painters Partition Problem
//Correct this and try eko spoj
#include<bits/stdc++.h>
using namespace std;
bool canPaint(int painters,int boards,int length[],int time){
    int timeSpent=0;
    int paintersUsed=1;
    for(int i=0;i<boards;i++){
        if(length[i]+timeSpent>time){
            paintersUsed++;
            if(paintersUsed>painters){
                return false;
            }
        }else{
            timeSpent+=length[i];
        }
    }
    return true;
}
void paintersPartition(int painters,int boards,int length[])
{
    int start=length[boards-1];
    int end=0;
    for(int i=0;i<boards;i++){
        end+=length[i];
    }int ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        bool isPossible=canPaint(painters,boards,length,mid);
        if(isPossible){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout<<ans;
}
int  main(){
    int painters;
    int boards;
    int length[boards];
    cin>>painters>>boards;
    for(int i=0;i<boards;i++){
        cin>>length[i];
    }
    paintersPartition(painters,boards,length);
}