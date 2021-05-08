#include<bits/stdc++.h>
using namespace std;
string replacePi(string str){
    if(str.length()==0){
        return "";
    }
    
    char ch = str[0];
    string ros = str.substr(1);
    string recursionResult = replacePi(ros);
    if(ch=='p' and recursionResult[0]=='i'){
        return "3.14"+recursionResult.substr(1);
    }else{
        return ch+recursionResult;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str; 
        cout<<replacePi(str)<<endl;
    }
}