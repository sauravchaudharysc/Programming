// Find shortest unique prefix to represent each word in the list.

// Example:

// Input: [zebra, dog, duck, dove]
// Output: {z, dog, du, dov}
// where we can see that
// zebra = z
// dog = dog
// duck = du
// dove = dov
//  NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 

#include<bits/stdc++.h>
using namespace std;
struct Trie{
    Trie *edges[26];
    int words;
    Trie(){
        for(auto i=0;i<26;i++){
            edges[i]=NULL;
        }
        words=0;
    }
};

void addToTrie(Trie* head,string s){
    int n = s.length();
    Trie* current=head;
    for(auto i=0;i<n;i++){
        current->words+=1;
        if(!current->edges[s[i]-'a']){
            current->edges[s[i]-'a']= new Trie();
        }
        current=current->edges[s[i]-'a'];
    }
}

string findPrefix(Trie *head,string s){
    int n=s.length();
    string prefix="";
    Trie *current=head;
    int i=0;
    current = current->edges[s[i]-'a'];
    prefix += s[i];
    for( i=1;i<n;i++){
        if(current->words ==1 ){
            return prefix;
        }
        current = current->edges[s[i]-'a'];
        prefix+=s[i];
    }
    return prefix;
}
int main(){
    vector<string>A{"zebra","dog","duck","dove"};
    vector<string>res;
    if(A.empty()){
        return 0;
    }
    Trie* head=new Trie();
    auto size=A.size();
    for(auto i=0;i<size;i++){
        addToTrie(head,A[i]);
    }
    for(auto j=0;j<size;j++){
        res.emplace_back(findPrefix(head,A[j]));
    }
        for(auto j=0;j<size;j++){
        cout<<res[j]<<" ";
    }

}