//BST Deletion
//In BST there are 3 types of nodes
/*  Nodes with 0 children
    Nodes with 1 children
    Nodes with 2 children
    
    1. Deletion of Nodes with 0 children is very easy.Simply delete and return NULL
    2. Deletion of Nodes with 1 children.Either left isnt null or right isnt null.
       If left isnt null.Then we return the child of that node to the parent of that node.
    3. Deletion of node With 2 Children.So we need to replace the deleting element with 
       inorder sucessor*/
#include <iostream>
#include<queue>
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
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
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

node* deleteInBST(node *root,int data){
    if(root==NULL){
        return NULL;
    }else if(data<root->data){
        root->left=deleteInBST(root->left,data); 
        return root;
    }
    else if(data==root->data){
        //Node with 0 Children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //Node with 1 Children
        if(root->left!=NULL && root->right==NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node *temp=root->right;
            delete root;
            return temp;
        }
        //Node with 2 Children
        node *replace=root->right;
        while(replace->left!=NULL){
            //Inorder Succesor ko yeh dhundke dega
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deleteInBST(root->right,data); 
        return root;
    }else{
        root->right=deleteInBST(root->right,data);
        return root;
    }
}
//Searching 
bool search(node *root,int data)
{
    if(root==NULL){
        return false;
    }
    if(data==root->data){
        return true;
    }
    if(root->data<=data){
        return search(root->right,data);
    }else{
        
        return search(root->left,data);
    }
}

int main(){ 
    node*root = build();
    inorder(root);
    cout<<endl;
    int s;
    cin>>s;
    root=deleteInBST(root,s);
    inorder(root);
    cout<<endl;
    
return 0;
}










