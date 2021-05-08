#include<bits/stdc++.h>
using namespace std;

string moveAllXtoEnd(string str){
    if(str.length()==0){
        return "";
    }
    char ch=str[0];
    string ros=str.substr(1);
    string recursionResult=moveAllXtoEnd(ros);
    if(ch=='x'){
        return recursionResult+ch;
    }else{
        return ch+recursionResult;
    }
}



int main(){
    string s;
    cin>>s;
    cout<<moveAllXtoEnd(s)<<endl;
}