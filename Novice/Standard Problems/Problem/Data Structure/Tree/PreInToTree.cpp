/*
Given preorder and inorder create the tree

Input Format
Enter the size of the preorder array N then add N more elements and store in the array denoting the preorder traversal of the tree. Then enter the size of the inorder array M and add M more elements and store the inorder traversal of the array.

Constraints
1 <= N, M <= 10^4

Output Format
Display the tree using a modified preorder function. For each node , first print its left child's data , then the data of the root itself , then the data of its right child. Do this for each node in a new line in preorder manner. If one of the children does not exist print END in its place. Refer to the sample testcase.

Sample Input
3
1 2 3
3
3 2 1
Sample Output
2 => 1 <= END
3 => 2 <= END
END => 3 <= END
Explanation
The above tree looks like

         1
       /
     2
   /
 3
*/
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

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        cout<<root->left->data<<" => ";
    }else{
        cout<<"END => ";
    }
    cout<<root->data<<" <= ";
    if(root->right!=NULL){
        cout<<root->right->data;
    }else{
        cout<<"END";
    }
    cout<<"\n";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n1;
    cin>>n1;
    int preOrder[n1];
    for(int i=0;i<n1;i++){
        cin>>preOrder[i];
    }
    int n2;
    cin>>n2;
    int inOrder[n2];
    for(int i=0;i<n2;i++){
        cin>>inOrder[i];
    }
    Node* root=createTree(inOrder,preOrder,0,n2-1);
    preorder(root);
}
