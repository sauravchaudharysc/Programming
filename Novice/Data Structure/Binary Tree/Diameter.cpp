//Diameter Of Tree
//Diameter of a tree is the longest distance between any node.
/*
Three Cases Arises
I.Diameter Passes Throught The Root 
II.Diameter Lies in the Left Subtree
III.Diameter Lies in the Right Subtree
answer=max(I,II,III);

If passes throught the root.
Diameter is equal to height of left sub-tree and right sub-tree
*/
#include<bits/stdc++.h>
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

int height(node *root)
{
    if(root==NULL){
        return 0;
    }
    //Left subtree tera height bata
    int ls=height(root->left);
    //Right subtree tera height bata
    int rs=height(root->right);
    //In C make a function to compute max
    return max(ls,rs)+1;
}
//Overall Complexity Here Becomes O(N^2).
//In Every function call we were calculating height and recursing 
// on left and right subtree
int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int h1= height(root->left);
    int h2= height(root->right);
    int op1= h1+h2;
    int op2= diameter(root->left);
    int op3= diameter(root->right);
    return max(op1,max(op2,op3));
}

//Diameter Bottom Up Approach to get Optimized Tree.
//Post Order Traversal
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}


int main(){
    node *root=buildTree();
    Pair p=fastDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
}