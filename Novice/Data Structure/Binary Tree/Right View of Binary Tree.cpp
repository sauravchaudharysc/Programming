//Right View Of Binary Tree 
/*Suppose you are given a binary tree and when you see from the left what will you observe.
 
 Tree Traversal
 
 Depth First 
 Pre-order
 In-order
 Post-order
 
 Breadth First 
 Level Order Traversal And last Element in Queue of Level is the Right Element.
 
 Depth First Search
 (root,level)
 We take the root and include it in the answer . 
 Then we go to the right subtree and include it in our answer and mark that level visited.
 We go and visit all the levels of right and include in our answer. After completion of right 
 we go to left and check is there any node present at a level which level is not visited yet.
 
 Or we can use one maxLevel variable and update it to maxLevel visited so far.
 */
 
 #include<iostream>
 #include<vector>
 using namespace std;
 //Time Space O(N)
 class TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x),left(NULL),right(NULL){}
 };
 
 class Solution{
     vector<int> v;
     int max_level=-1;
     void helper(TreeNode *root,int level){
        if(root==NULL){
            return;
        } 
        if(level>max_level){
            max_level=level;
            v.push_back(root->val)''
        }
        helper(root->right,level+1);
        helper(root->left,level+1); 
     }
     vector<int> rightSideView(TreeNode *root){
         helper(root,0);
     }
 }
 int main()
 {
     
 }