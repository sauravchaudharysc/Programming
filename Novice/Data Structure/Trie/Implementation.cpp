#include<iostream>
#include<unordered_map>
using namespace std;
//A node is created which contains a data and a map which contains the next character value and address
class Node{
    public:
         char data;
         unordered_map<char,Node*>children;
         bool terminal;
         Node(char d){
             data=d;
             //Initially terminal is marked false updated while inserting character
             terminal=false;
         }
};
class Trie{
  Node *root;
  int cnt;
  public:
     Trie(){
         root = new Node('\0');
         cnt =0;
     }
     void insert(char *w){
         //Root Node
         Node *temp=root;
         //Iterate the loop while all the characters of string isnt inserted
         for(int i=0;w[i]!='\0';i++){
             char ch=w[i];
             //If the characters are present check for next
             if(temp->children.count(ch)){
                 temp=temp->children[ch];
             }//Not present then insert them
             else{
                 Node *n=new Node(ch);
                 temp->children[ch] =n;
                 temp=n;
             }
         }
         //Marked true so that while finding we can know the word is present or not
         temp->terminal=true;
     }
     //To find the word in trie
     bool find(char *w){
         Node* temp = root;
         //Iterate till all the characters of the string is found
         for(int i=0;w[i]!='\0';i++){
             char ch=w[i];
             //Here count is c++ function which helps here to search character.
             //If found return 1 nor return 0.
             if(temp ->children.count(ch)==0){
                 return false;
             }else{
                 temp=temp->children[ch];
             }
         }
        //Return and if present it returns true. Take a example of not and note. It contains terminal at both t and e.So if stops at t then this temp->terminal return true          
         return temp->terminal;
     }
};

int main(){
    Trie t;
    char words[][10]={"a","hello","not","news","apple"};
    char w[10];
    cin>>w;
    for(int i=0;i<5;i++){
        t.insert(words[i]);
    }
    if(t.find(w)){
        cout<<"present";
    }else{
        cout<<"No";
    }
}