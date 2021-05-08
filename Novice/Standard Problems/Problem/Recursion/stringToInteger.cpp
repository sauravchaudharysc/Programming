#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll getStringToInteger(string s){
    ll x=0;
    for(int i=0;i<s.size();i++){
        x += (s[i]-48)*pow(10,s.size()-1-i);
    }
    return x;
}

int main(){
    string s;
    cin>>s;
    cout<<getStringToInteger(s);
}