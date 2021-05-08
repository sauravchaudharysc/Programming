/*Naive Pattern Matching
Iterate using the i pointer it will traverse till stringsize-patternsize.Here we will check ith patterns
matches the jth character or not. If matches then we will increase both i and j by 1. If J will be equal
to pattern size then there is pattern.
In worst case what will be doing will be iterating over (n-m)*m -- for n nearly equal to m. 0(n^2)*/
#include<bits/stdc++.h>
using namespace std;
void NaiveSearch(string str,string pat){
    for(int i=0;i<= str.size() - pat.size();i++){
        int j;
        for(j=0;j<pat.size();j++){
            if(str[i+j] != pat[j]){
                break; //If unequal
            }
        }
        if(j==pat.size()){
                cout<<"Pattern is found at "<<i<<endl;
            }
    }
}
int main()
{
    string s="abbacdab";
    string s1="ab";
    NaiveSearch(s,s1);
}