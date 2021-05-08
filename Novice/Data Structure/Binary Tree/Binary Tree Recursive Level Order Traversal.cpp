//Level Order Print Recursive
//Input :- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
//Worst Case Complexity :- For a skewed tree. Height calculation O(N).
//For each level we will call kth level. So order is O(N^2)
/*
To print level wise
1st-> We need height or level of the tree.
2nd-> Print each level
*/
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
//As you go down you will reduce the value of k by 1.
//At a point when k==1 that is the level to printed.
void printKthLevel(node *root,int k){
    //If Node isnt present
    if(root==NULL){
        return;
    }
    //Node is existing and k==1
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    //Decrease the value of k and descend down
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}
void levelOrderTraversal(node *root){
    int h=height(root);
    //Kth ka base case 1. Islie 1 seh suru karo
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
    }
}
int main(){
    node *root=buildTree();
    levelOrderTraversal(root);
}