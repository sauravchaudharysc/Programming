/*Rolling Hash Function:-
Keep a prime number as a base.We will multiply the ACII of every character
with corresponding power of prime number*/

#include<bits/stdc++.h>
#define ll long long int
#define prime 119
using namespace std;
 ll createHashValue(string str,int n) //O(m)
 {
    ll result=0;
    for(int i=0;i<n;i++){
        result +=(ll)(str[i]*(ll)pow(prime,i)); //(str[0]*3^0+str[1]*3^1+......+str[n]*3^n)
    }
    return result;
 }
 //Recalculate has for input string
 //O(1)
 ll recalculateHash(string str,int oldIndex, int newIndex,ll oldHash,int patLength){
    ll newHash = oldHash - str[oldIndex];
    newHash/=prime;
    newHash+=(ll)(str[newIndex]*(ll)(pow(prime,patLength-1)));
    return newHash;
 }
 bool checkEqual(string str1,string str2,int start1,int start2,int end1,int end2){
     //Length of substring
     if(end1-start1 != end2-start2){
         return false;
     }
     while(start1<=end1 and start2<=end2){
         if(str1[start1]!=str2[start2]){
             return false;
         }
         start1++;
         start2++;
     }
     return true;
 }
 int main()
 {
    string str="ababcabdab";
    string pat="abd";
    ll patHash=createHashValue(pat,pat.length());
    ll strHash=createHashValue(str,pat.length());
    for(int i=0;i<=str.length()-pat.length();i++){
        if(patHash == strHash && checkEqual(str,pat,i,0,i+pat.length()-1,pat.length()-1)){
            cout<<i<<endl;
        }
        if(i<str.length()-pat.length()){
            strHash = recalculateHash(str,i,i+pat.length(),strHash,pat.length());
        }
    }
 } 