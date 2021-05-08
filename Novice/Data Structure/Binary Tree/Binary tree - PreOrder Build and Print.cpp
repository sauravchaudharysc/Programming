//Build a Binary Tree
//Recursive Aprroach 
//Input :- 3 4 -1 6 -1 -1 5 1 -1 -1 -1 
//-1 Represent NULL. Returns from that node
/*
structure of node
int data;
node *lchild,*rchild;

Top Down
Build Root
Recursively Build Left and Right*/

#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    //Encountering -1 means to return from that node
    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise,print root first followed by subtrees(children)
    cout<<root->data<<" ,";
    print(root->left);
    print(root->right);
}

int main(){
    node *root=buildTree();
    print(root);
}