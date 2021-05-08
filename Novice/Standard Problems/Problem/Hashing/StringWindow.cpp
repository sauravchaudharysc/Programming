/*Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring

Input Format
The first line of the input contains string1. String1 can be a string containing spaces also. The second line of the input contains string2. String2 can be a string containing spaces also.

Constraints
Length of both the strings can be at max 10^4

Output Format
Output the substring in a single line. If no such substring exist then output "No String" without quotes

Sample Input
qwerty asdfgh qazxsw
qas
Sample Output
qazxs
Explanation
The substring "qazxs" is the shortest substring of s1 that contains all the characters of s2.*/
#include<bits/stdc++.h>
using namespace std;
string minimumLengthSubstring(string str,string pat){
    int len1=str.length();
    int len2=pat.length();
    if(len2>len1){
        cout<<"No String"<<endl;
        return "";
    }
    unordered_map<char,int>pathash,strhash;
    for(int i=0;i<len2;i++){
        pathash[pat[i]]++;
    }
    int start=0,start_index=-1,min_length=INT_MAX;
    int count=0;
    for(int j=0;j<len1;j++){
        //Count occurence of characters of string
        strhash[str[j]]++;
        
        /*If strings char matches with pattern's char and string character 
        frequency <= pattern frequency*/
        if(pathash[str[j]]!=0 && strhash[str[j]]<=pathash[str[j]]){
            count++;
        }
        
        //Is the count equals to the length of pattern 
        if(count==len2){
            /*Try to minimize the window i.e.,check if any character is occuring 
            more no. of times than it occurence in pattern or it contains useless
            charcter at begining
            */
            while(strhash[str[start]]>pathash[str[start]] || pathash[str[start]]==0){
                if(strhash[str[start]]>pathash[str[start]]){
                    strhash[str[start]]--;
                }
                start++;
            }
            
            int window_length=j-start+1;
            if(min_length>window_length){
                min_length=window_length;
                start_index=start;
            }
        }
    }
    
    // If no window found 
    if (start_index == -1){
     cout<<"No String"<<endl; 
     return ""; 
    } 
  
    // Return substring starting from start_index and length min_len 
    return str.substr(start_index, min_length); 
}
int main(){
  string str;
  string pat;
  getline(cin,str);
  getline(cin,pat);
  cout<<minimumLengthSubstring(str,pat)<<endl;
}