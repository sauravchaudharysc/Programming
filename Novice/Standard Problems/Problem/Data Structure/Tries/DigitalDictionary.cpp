/*Peter found a digital dictionary which is far better than normal dictionaries. The digital dictionary has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string in lexicographical order. Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. And if no such words are available for a given search word, add this word to your dictionary.

Input Format
Single integer N which denotes the number of words which are to be stored in the database of the dictionary.
N lines of input, where in each line there is a string made up of lowercase/uppercase letter Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user.

Constraints
1≤N≤30000
sum(len(stringi)) ≤ 2∗10^5
1≤Q≤10^3

Output Format
If word with prefix exists in the database, then you need to print all the words with the given prefix in lexicographical order in separate lines else you need to print "No suggestions" without the inverted commas.

Sample Input
4
pet
peter
rat
rack
5
pe
pet
r
rac
rat
Sample Output
pet
peter
pet
peter
rack
rat
rack
rat
Explanation
For query 1 : Input = "pe"
We print "pet" and "peter".
For query 2 : Input = "pet"
We print "pet" and "peter".
For query 3 : Input = "r"
We print "rack" and "rat".
For query 4 : Input = "rac"
We print "rat.
For query 5 : Input = "rat"
We print "rat".*/
#include<bits/stdc++.h>
using namespace std;
//To store the input string and to store the string printed till now
unordered_map<string,int>pp,kk;

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

void print(string s,trie *root){
   bool k=false;
   for(int i=0;i<26;i++){
       if(root->children[i]!=NULL){
           k=true;
           break;
       }
   }
   
   if(!k && kk.find(s)==kk.end()){
       cout<<s<<"\n";
       kk[s]++;
       return;
   }
   for(int i=0;i<26;i++){
       if(root->children[i]!=NULL){
           //To get the character to insert
           char c='a'+i;
           string k(1,c);
           s=s+k;
           if(pp.find(s)!=pp.end() && kk.find(s)==kk.end()){
               cout<<s<<"\n";
               kk[s]++;
           }
           print(s,root->children[i]);
           s=s.substr(0,s.size()-1);
       }
   }
   return;
}

//A function to search for the string is present or not
int search(string s,trie *root){
    trie *curr=root;
    for(int i=0;i<s.length();i++){
        //To get a unique index
        int indx=s[i]-'a';
        //To make a trie node and insert
        trie *child=curr->children[indx];
        //If not found then return -1 from here
        if(child==NULL){
            return -1;
        }else{
            curr=child;
        }
    }
    if(pp.find(s)!=pp.end()){
        cout<<s<<"\n";
        kk[s]++;
    }
    print(s,curr);
    return 0;
}
    

int main(){
 int n,m;
 cin>>n;
 trie *root=new trie();
 while(n--){
     string s;
     cin>>s;
     pp[s]++;
     insert(s,root);
 }
 cin>>m;
 while(m--){
     string s;
     cin>>s;
     kk.clear();
     if(search(s,root)==-1){
         insert(s,root);
         pp[s]++;
         cout<<"No suggestions\n";
     }
 }
 return 0;
}