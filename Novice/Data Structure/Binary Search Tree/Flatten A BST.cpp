//Flatten A BST
//BST into linked list without creating the linked list
//Using the same node of BST a sorted linked list. 
//Input 5 3 7 1 6 8 -1
//We need to change basically three Pointers.
/*Think of it recursively
You have a node you have a left sub-tree and right-sub tree.
Get a linked list from left-subtree.
Get a linked list from right-subtree.
Join it with node . 
*/#include <iostream>
#include<climits>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
class linkedList{
    public:
        node*head;
        node*tail;
};

linkedList flatten(node*root){
    linkedList l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    //Leaf node
    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
        return l;
    }
    //Left is Not Null
    if(root->left!=NULL && root->right==NULL){
        linkedList leftLL=flatten(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
        return l;
    }
    //Right isnt NULL
    if(root->left==NULL && root->right!=NULL){
        linkedList rightLL=flatten(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
        return l;
    }
    //Both sides arent NULL
    linkedList leftLL= flatten(root->left);
    linkedList rightLL= flatten(root->right);
    leftLL.tail->right=root;
    root->right=rightLL.head;
    l.head=leftLL.head;
    l.tail=rightLL.tail;
    return l;
}


int main(){ 
    node*root = build();
    inorder(root);
    cout<<endl;
    linkedList l=flatten(root);
    node *temp=l.head;
    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->right;
    }
    cout<<endl;
    
return 0;
}










