/*You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
Note : In case of node with 2 children, consider its inorder successor as its replacement.

Input Format
First line contains integer t as number of test cases.
Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.

Constraints
1 < t < 100
1< n,m < 1000

Output Format
Print the preorder traversal of the final resultant tree.

Sample Input
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output
6 4 7 8 
Explanation
Initially the tree looks like

             5
          /      \
       3           7
    /     \      /    \
   2       4    6      8
After the deletion , the tree looks like

               6
            /     \
           4       7
                     \
                      8
We print the preorder of the final tree.*/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

Node* inOrderSucessor(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

Node* insert(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(root->data<key){
        root->right=insert(root->right,key);
    }
    if(root->data>key){
        root->left=insert(root->left,key);
    }
    return root;
}

Node* deletenode(Node* root,int key){
    
    if(root==NULL){
        return root;
    }
    
    if(root->data<key){
        root->right=deletenode(root->right,key);
    }
    
    else if(root->data>key){
        root->left=deletenode(root->left,key);
    }
    
    else{
        //Nodes with one child or no child
        if(root->left==NULL){
            Node *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node *temp=root->left;
            free(root);
            return temp;
        }
        
        Node *temp=inOrderSucessor(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}

void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2;
        cin>>n1;
        Node *root=NULL;
        for(int i=0;i<n1;i++){
            int x;
            cin>>x;
            root=insert(root,x);
        }
        cin>>n2;
        for(int i=0;i<n2;i++){
            int x;
            cin>>x;
            root=deletenode(root,x);
        }
        preOrder(root);
        cout<<endl;
    }
}