/*
Given a Binary Tree, write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)

Input Format
The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT.

Constraints
2 ≤ N ≤ 10^3

Output Format
A single integer denoting the size ( no of nodes in tree ) of largest BST in the given tree.

Sample Input
4
60 65 50 70
50 65 60 70
Sample Output
2
Explanation
The tree looks like

             60
          /      \
       65           70
     /           
   50       
The largest BST subtree is

       65           
     /           
   50       
which has the size 2 i.e. it has 2 nodes in it.*/
#include<bits/stdc++.h>
using namespace std;
class Node{
   public:    
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class Info{
  public:    
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};
int d1=0;
Node *createTree(int inOrder[],int preOrder[],int b1,int b2){
    if(b2<b1){
        return NULL;
    }
    int k= preOrder[d1++];
    Node *root= new Node(k);
    int l=b1;
    while(inOrder[l]!=k){
        l+=1;
    }
    root->left=createTree(inOrder,preOrder,b1,l-1);
    root->right=createTree(inOrder,preOrder,l+1,b2);
    return root;
}

Info largestBstBt(Node *root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    } 
    
    Info l = largestBstBt(root->left); 
    Info r = largestBstBt(root->right); 
    
    //Current Node+BinaryTree Left node size and right node size
    //Total size below the node is returned here
    Info ret; 
    ret.size = (1 + l.size + r.size); 
    
    // If whole tree rooted under current root is BST. 
    if (l.isBst && r.isBst && l.max < root->data && r.min > root->data) 
    { 
        ret.min = min(l.min, min(r.min, root->data)); 
        ret.max = max(r.max, max(l.max, root->data)); 
  
        // Update answer for tree rooted under current 'root' 
        ret.ans = ret.size; 
        ret.isBst = true; 
    
        return ret; 
    }      
    ret.ans = max(l.ans, r.ans); 
	ret.isBst = false; 

	return ret; 
}

int main(){
    int n2;
    cin>>n2;
    int preOrder[n2];
    for(int i=0;i<n2;i++){
        cin>>preOrder[i];
    }
    int inOrder[n2];
    for(int i=0;i<n2;i++){
        cin>>inOrder[i];
    }
    Node* root=createTree(inOrder,preOrder,0,n2-1);
    cout<<largestBstBt(root).ans<<endl;
}