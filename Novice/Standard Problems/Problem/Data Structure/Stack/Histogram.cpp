/*HistoGram 
We need to find the maximum area covered. We use a stack , we push all the element once and 
pop it out once so the time complexity is O(N).

We use a stack. We push and incremenet the index if we get a larger area bar in consecutive
path. We pop if we get a smalled height bar.On poping it out.We calculate the area for it.
Two cases arises:- If the stack is empty then the bar is smallest among all so we multiply
it height by by i. If not empty then i-s.top()-1.

After the complete iteration the stack may contain some smaller element. We need to utitlize them
and caluclate the area. SO we do the same here for area by poping the elements.Following the 
above two cases

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll hist[100005];
ll largestArea(ll hist[],ll n){
    stack<int>st;
    ll max_Area=0;
    ll Area;
    ll top;
    ll i=0;
    while(i<n){
        if(st.empty() || hist[st.top()]<=hist[i]){
            st.push(i++);
        }else{
           top=st.top();
           st.pop();
           Area=hist[top]*(st.empty()?i:(i-st.top()-1));
           if(max_Area<Area){
               max_Area=Area;
           }
        }
    }
    
    while(st.empty()==false){
        top=st.top();
        st.pop();
        Area=hist[top]*(st.empty()?i:(i-st.top()-1));
        if(max_Area<Area){
           max_Area=Area;
        }
    }
    return max_Area;
}

int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>hist[i];
    }
    cout<<largestArea(hist,n)<<endl;
}