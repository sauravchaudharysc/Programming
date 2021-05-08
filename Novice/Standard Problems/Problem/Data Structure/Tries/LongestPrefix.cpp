/*Longest prefix matching
Given a dictionary of words and an input string, find the longest prefix of the string which is also a word in dictionary.
Examples:

Let the dictionary contains the following words:
{are, area, base, cat, cater, children, basement}

Below are some input/output examples:
--------------------------------------
Input String            Output
--------------------------------------
caterer                 cater
basemexy                base
child                   < Empty >
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>pp;

class trie{
    public:
        trie **children;
        trie(){
            children=new trie*[26];
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};

//A function to insert string in a trie
void insert(string s,trie* root){
    if(s.empty()){
        return;
    }    
    //To get a unique index in array for each character
    int indx=s[0]-'a';
    trie *child;
    child=root->children[indx];
    //The particular character is present or not.
    //if not then index is NULL
    if(child==NULL){
        //Create a child bucket
        child=new trie();
        //Connect the root to child bucket
        root->children[indx]=child;
    }
    insert(s.substr(1),child);
}

//A function to search for the string is present or not
int search(string s,trie *root){
    trie *curr=root;
    string str="";
    for(int i=0;i<s.length();i++){
        //To get a unique index
        int indx=s[i]-'a';
        //To make a trie node and insert
        trie *child=curr->children[indx];
        if(child==NULL){
            break;
        }else{
            str+=s[i];
            curr=child;
        }
    }
    if(pp.count(str)){
     cout<<str<<"\n";
     return 1;
    }
    return -1;
}
    

int main(){
 int n,m;
 cin>>n;
 trie *root=new trie();
 while(n--){
     string s;
     cin>>s;
     insert(s,root);
 }
 cin>>m;
 while(m--){
     string s;
     cin>>s;
     if(search(s,root)==-1){
         pp[s]++;
         insert(s,root);
         cout<<"No suggestions\n";
     }
 }
 return 0;
}