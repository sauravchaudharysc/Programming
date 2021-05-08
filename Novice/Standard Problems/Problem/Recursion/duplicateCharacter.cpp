/*Remove Duplicate Character in String*/
#include<bits/stdc++.h>
using namespace std;
void stringRemoveDuplicates(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char a = s[0];
    char b = s[1];
    string ros=s.substr(1);
    if(a==b){
        ans=ans;
    }else{
        ans=ans+a;
    }
    stringRemoveDuplicates(ros,ans);
    
}
int main()
{
  string s;
  string ans="";
  cin>>s;
  stringRemoveDuplicates(s,ans);
}