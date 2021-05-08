#include<bits/stdc++.h>
using namespace std;
void findPermutation(string str){
    int p=0,q=0;
    int i;
    vector<int>ans;
    int n=str.length();
    for(i=0;i<n;i++){
        ans.push_back(i+1);
        if(str[i]=='I'){
            while(p<q){
                int t=ans[p];
                ans[p]=ans[q];
                ans[q]=t;
                p++;
                q--;
            }
            p=i+1;
            q=i;
        }
        q++;
    }
    ans.push_back(n+1);
    while(p<q){
                int t=ans[p];
                ans[p]=ans[q];
                ans[q]=t;
                p++;
                q--;
    }
    
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }
}

int main(){
     string str;
     cin>>str;
     findPermutation(str);
}