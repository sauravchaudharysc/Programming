#include<bits/stdc++.h>
using namespace std;

/*A trie node which contains a data and a map which contains the next 
character as key and the address of the next character as value*/

class TrieNode{
    public:
        //To store the current node data
        char data;
        //To store the next node character and address of that node
        unordered_map<char,TrieNode*>child;
        //To indicate end of word
        bool terminal;
        
        //For new node
        TrieNode(char d){
            data=d;
            //Terminal is updated at the completion of insertion
            terminal=false;
        }
};

bool deleteTrieNode(TrieNode *&curr,string str,int i){
    
    if(str[i]){
        if(curr->child.find(str[i])!=curr->child.end()&& deleteTrieNode(curr->child[str[i]],str,i+1)&& curr->terminal==false){
            if(curr->child.empty()==false){
                delete curr;
                return true;
            }else{
                return false;
            }
        }
    }
    if(str[i]=='\0' && curr->terminal){
        if(curr->child.empty()==false){
                delete curr;
                return true;
            }else{
                curr->terminal=false;
                return false;
            }
    }
    return false;
}
class Trie{
     //Root node
     TrieNode *root;
     public:
        Trie(){
            root= new TrieNode('\0');
        }

    void insert(string str){
        //To get a pointer to root node 
        TrieNode* temp=root;
            
         //A loop to insert string in trie 
         for(int i=0;i<str.length();i++){
             char ch=str[i];
             /*To check the current character to be inserted 
             is present as TrieNode or not.count function return
             an boolean value*/
             if(temp->child.count(ch)){
                //If yes it is present than go to that trie node
                temp=temp->child[ch];
             }else{
                //If not present create a trie node
                TrieNode* n= new TrieNode(ch);
                temp->child[ch]=n;
                temp=n;
             }
        }
        temp->terminal=true;
    }
    
    bool search(string str){
        TrieNode *temp=root;
        //Iterate till all the characters of the string is found 
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp ->child.count(ch)==0){
                 return false;
            }else{
                 temp=temp->child[ch];
            }
        }
        //If the current node is terminal of word
        return temp->terminal;
    }
    
    void print(string str){
        if(search(str)){
            cout<<str<<endl;
        }else{
            cout<<"Not found"<<endl;
        }
    }
    
    bool idelete(string str){
        return deleteTrieNode(root,str,0);
    }
};

int main(){
    Trie t;
    string s;
    for(int i=0  ;i<5;i++){
        cin>>s;
        t.insert(s);
    }
    while(1){
        string w;
        cin>>w;
        t.print(w);
        if(t.search(w)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<t.idelete(w);
    }    
}
