#include<bits/stdc++.h>

using namespace std;
class TrieNode{
  public:    
    int data;
    unordered_map<int,TrieNode*>child;
    bool terminal;
    TrieNode(int d){
        data=d;
        terminal=false;
    }
};

class Trie{
    TrieNode *root;
    public:
        Trie(){
            root=new TrieNode('\0');
        }
    void insert(int arr[],int m){
        bool flag=0;
        TrieNode* temp=root;
        for(int i=0;i<m;i++){
            int x=arr[i];
             if(temp->child.count(x)){
                temp=temp->child[x];
             }else{
                TrieNode* n=new TrieNode(x);
                temp->child[x]=n;
                flag=1;
                temp=n;
            }   
        }
        temp->terminal=true;
        if(flag==1){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
    }
};

Trie t;
void inputMatrix(int a[100][100],int n,int m){
    int arr[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[j]=a[i][j];
        }
        t.insert(arr,m);
    }
}
int main(){
    int a[100][100], n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    inputMatrix(a,n,m);
}