//Aggressive Cows
//We have to come up with a solution that minimum distance between them is large as possible
#include<bits/stdc++.h>
using namespace std;
/*You get the stall place for stall array.I place the array at first place. So i go to the
next stall and check the distance between the next stall and if it greater than equal to 
minimum Seperation place the cow and update the last cow place*/
bool canPlaceCows(int stalls[],int n,int c,int min_Seperation)
{
    int last_cow = stalls[0];
    int count=1;
    for(int i=1; i<n; i++){
        if(stalls[i]-last_cow>=min_Seperation){
            last_cow = stalls[i];
            count++;
            if(count==c){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
 
    while(t--){
        int n;
        cin>>n;
        int stalls[n];
        int cows;
        cin>>cows;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls,stalls+n);
        int start = 0;
        int end = stalls[n-1] - stalls[0];
        while(start<=end){
            int mid = (start+end)/2;
            bool cowsRakhPaye = canPlaceCows(stalls,n,cows,mid);
            if(cowsRakhPaye){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}