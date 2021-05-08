//Binary Tree To Doubly Linked List
//Input :- 10 20 5 -1 -1 9 3 -1 -1 -1 2 -1 6 -1 8 -1 -1
/*Convert Left Sub-Tree to Doubly Linked List
Attach Root with the Left Sub-Tree Based Linked List.

Convert Right Sub-tree to Doubly Linked List and attach it.*/

#include<iostream>
using namespace std;
//Time and Space O(N)
class TreeNode{
  public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    /*TreeNode(int data): val(x) ,left(NULL),right(NULL){}
     */
};

class Solution{
    TreeNode* prev;
    TreeNode* head;
    
    void b2dll(TreeNode *root){
        if(root == NULL) return;
        b2dll(root->left);
        //To Do
        //If the node is first node then it will be the head
        if(prev==NULL){
            head=root;
        }else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        b2dll(root->right);
    }
}