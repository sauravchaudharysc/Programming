//Biased Standing Concept
//We should do the sorting of the input array ranklist and assign them in ascending order.
//We will use count sort implementation because n is not a bigrange.
#include<bits/stdc++.h>
using namespace std;
int abs(int i,int j)
{
    if(i-j>0){
        return i-j;
    }
    else{
        return j-i;
    }
}
int main()
{
    int arr[1000000]={0};
    int t,n;
    cin>>t;
    while(t--){
        memset(arr,0,sizeof(arr));
        string name;
        int n,rank;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>name>>rank;
            arr[rank]++;
        }
        //Greedy Apprroach-assign the team nearest rank possible
        int actual_rank=1;
        int sum=0;
        for(int i=1;i<=n;i++){
            while(arr[i]){
                sum+=abs(actual_rank,i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout<<sum<<endl;
    }
}