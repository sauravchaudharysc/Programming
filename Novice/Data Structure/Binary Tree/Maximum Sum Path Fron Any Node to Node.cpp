//Maximum Sum Path From Any Node TO Node
/*
We need to path from any node to node
For any tree rooted at a NODE "R" will maximum 
if they cover the Left Sub Tree , Root and Right Sub tree
if they cover the Left subtree+root.
if they cover the Left root+right sub tree.
if they cover the root
*/


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
    int globalMax=INT_MIN;
    
    int maxPathNode2Node(TreeNode* root){
        //Base case
        if(root=NULL){
            return 0;
        }
        int ls = maxPathNode2Node(root->left); //LST
        int rs= maxPathNode2Node(root->right); //RST 
        //SelfWork
        int cand1=root->val;
        int cand2=ls+root->val;
        int cand3=rs+root->val;
        int cand4=ls+rs+root->val;
        globalMax=max(cand1,max(cand2,max(cand3,max(cand4,globalMax))));
        return max(ls,max(rs,0))+root->val;//My contribution to my parent
    }
}
int main()
{
}
