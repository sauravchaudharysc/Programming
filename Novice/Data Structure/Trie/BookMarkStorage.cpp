#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char,Node*>children;
    Node(char data){
        this->data=data;
        this->terminal=false;
    }
};
class Trie{
    public: 
    Node *root;
    int count;
    Trie(){
        this->root=new Node('\0');
        this->count=0;
    }
    void addWord(string str){
        Node *temp=root;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }else{
                Node *n=new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }
    bool find(string str){
         Node* temp = root;
         for(int i=0;i<str.size();i++){
             char ch=str[i];
             if(temp ->children.count(ch)==0){
                 return false;
             }else{
                 temp=temp->children[ch];
             }
         }
         return temp->terminal;
     }
};
int main()
{
    Trie t;
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        t.addWord(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        cout<<t.find(str)<<endl;
    }
}