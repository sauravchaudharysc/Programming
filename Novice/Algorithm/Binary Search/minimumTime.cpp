#include<bits/stdc++.h>
using namespace std;
bool isPossible(int rank[],int cooks,int prata,int minutes)
{
    int timeelapsed=0;
    int cookUsed=1;
    int cooked=0;
    int i=0;
    int rate=rank[i];
    while(cooked!=prata){
            timeelapsed=timeelapsed+rank[i]*rate;
            rate++;
            cooked++;
        if(timeelapsed>minutes){
            cooked--;
            cookUsed++;
            i++;
            timeelapsed=0;
            rate=1;
            if(cookUsed>cooks){
                return false;
            }
        }    
    }
    return true;
}
void minutesNeeded(int rank[],int cooks,int prata)
{
    int start=0;
    int ans=INT_MAX;
    int end= (prata*(prata+1))/2;
    while(start<=end){
        int mid=(start+end)/2;
        bool canCook=isPossible(rank,cooks,prata,mid);
        if(canCook){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int prata;
    int cooks;
    cin>>prata>>cooks;
    int *rank=new int[cooks];
    for(int i=0;i<cooks;i++){
        cin>>rank[i];
    }
    minutesNeeded(rank,cooks,prata);
    }
}