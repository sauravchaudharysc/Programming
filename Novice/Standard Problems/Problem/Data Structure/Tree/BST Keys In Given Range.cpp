/*You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

Input Format
First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

Constraints
1 < t < 20
1 < n < 50

Output Format
For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive). Refer to the sample testcase for exact output format.

Sample Input
1
5
4 3 2 5 6
3 5
Sample Output
# Preorder : 4 3 2 5 6 
# Nodes within range are : 3 4 5 
Explanation
The tree looks like

             4
          /      \
       3           5
    /                \
   2                  6
The nodes between the range 3 to 5 are 3,4,5.*/
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

void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root,int start,int end){
    if(root==NULL){
        return;
    }
    inOrder(root->left,start,end);
    if(start<=root->data && root->data<=end){
        cout<<root->data<<" ";
    }
    inOrder(root->right,start,end);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* root = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int key;
            cin>>key;
            root=insert(root,key);
        }
        int start,end;
        cin>>start>>end;
        cout<<"# Preorder : ";
        preOrder(root);
        cout<<"\n";
        cout<<"# Nodes within range are : ";
        inOrder(root,start,end);
        cout<<"\n";
    }
}