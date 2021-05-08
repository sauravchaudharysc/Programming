//Preorder,Inorder,Postorder 
//Input :- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
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

void printPreOrder(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise,print root first followed by subtrees(children)
    cout<<root->data<<" ,";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(node *root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
     //Otherwise,print root first followed by subtrees(children)
    cout<<root->data<<" ,";
    printInOrder(root->right);
}
void printPostOrder(node *root){
    if(root==NULL){
        return;
    }
    printPostOrder(root->left);
     //Otherwise,print root first followed by subtrees(children)
    cout<<root->data<<" ,";
    printPostOrder(root->right);
}

int main(){
    node *root=buildTree();
    
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;
}