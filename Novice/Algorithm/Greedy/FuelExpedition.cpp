//Fuel Expedition
/*We should refuel at that places having higher Fuel 
capacity to get minimum number of stops.
So we will do sorting for fuel station upto which we can reach 
with current capacity.Keep a note of fuel station that are available.
If at any point i am in shortage of fuel i will pick the largest and refuel and do 
if it happens again. So we can use priority queue data structure.
*/


#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first>p2.first;
}
int main()
{
    int t;
    cin>>t;
    int n,d,f,D,F,prev=0;
    while(t--){
        int flag=0;
        vector<pair<int,int>>v;
        priority_queue<int> pq;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        //Sorting on the basis of location
        sort(v.begin(),v.end(),compare);
        cin>>D>>F;
        //Update the distance of fuel station from the truck
        for(int i=0;i<n;i++){
            v[i].first=D-v[i].first;
        }
        int ans=0;
        //prev denotes the previous city we have visited
        prev=0;
        //current city
        int x=0;
        while(x<n){
            //If we have enough fuel to go to next city
            if(F >= (v[x].first - prev)){
                F=F-(v[x].first - prev);
                pq.push(v[x].second);
                prev=v[x].first;
            }else{
                //Check if you have some fueling station visited in the priority
                if(pq.empty()){
                    flag=1;
                    break;
                }
                //Otherwise refuel the truck with fuel stations with higher capacity
                F+=pq.top();
                //Remove that fuel station from priority queue
                pq.pop();
                ans++;
                continue;
            }
            //To update city
            x++;
        }
        //Actually travelled through n fuel stations
        //what is left you have to reach the town from the last fuel stations
        if(flag==1){
            cout<<-1<<endl;
            continue;
        }
        //Otherwise
        D = D - v[n-1].first;
        if(F>=D){
            cout<<ans<<endl;
            continue;
        }
        while(F<D){
            if(pq.empty()){
                flag=1;
                break;
            }
            F+=pq.top();
            pq.pop();
            ans++;
        }
        if(flag==1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}