// BALIFE - Load Balancing

/*Calculate find load on each processor. That is easy just sum up and divide by N
  If this is not an integer then return -1.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1000000];
    int n,i,val,diff;
    while(1)
    {
        //Take Input Of Current Test Cases
        int max_load =0,load=0;
        cin>>n;
        //Stop taking input if N = -1
        if(n==-1){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //Find the load that is to be divided equally
        for(int i=0;i<n;i++){
            load+=arr[i];
        }
        if(load%n!=0){
            cout<<-1<<endl;
            continue;
        }
        load=load/n;
        diff=0;
        //Greedy Step 
        for(int i=0;i<n;i++){
            //Find the difference between final load to be assigned and current load
            diff += (arr[i]-load);
            int ans = max(diff,-diff);
            max_load= max(max_load,ans);
        }
        cout<< max_load<<endl;
    }
}