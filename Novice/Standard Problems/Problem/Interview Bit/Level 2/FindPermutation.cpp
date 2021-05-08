#include<bits/stdc++.h>
using namespace std;
void findPermutation(string str){
    stack<int>st;
    vector<int>ans;
    int n=str.length();
    for(int i=0;i<n;i++){
        st.push(i+1);
        if(str[i]=='I'){
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
    }
    st.push(n+1);
    while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
     string str;
     cin>>str;
     findPermutation(str);
}