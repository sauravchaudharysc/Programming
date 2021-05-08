//Debug Needed

//Distance between the nodes of a Binary tree
/*The shortest path between the nodes i.e the edges covered to reach them.

LCA is the node in which p and q are descendent.

distance(p,q)=distance(root,p)+distance(root,q)-  2*distance(root,lca of p and q)*/

//Here Is The LCA Implementation

#include<iostream>
using namespace std;
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
TreeNode* buildTree(){
    int d;
    cin>>d;
    //Encountering -1 means to return from that node
    if(d==-1){
        return NULL;
    }
    TreeNode* root=new TreeNode(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

class Custom{
  public:    
    bool hasKeyP;
    bool hasKeyQ;
    TreeNode* node; //Store the value of LCA
};

Custom* helper(TreeNode *root,TreeNode *p,TreeNode *q){
    //Base case
    if(root==NULL){
        return NULL;
    }
    
    Custom* leftans = helper(root->left,p,q);
    //Both p and q in my left subtree 
    if(leftans!= NULL and leftans->node!=NULL){
        return leftans;
    }
    
    Custom* rightans = helper(root->right,p,q);
    //Both p and q in my right subtree
    if(rightans!= NULL and rightans->node!=NULL){
        return rightans;
    }
    Custom* result=new Custom();
    //One of them is inside left subtree and other is in right subtree.
    if(leftans!=NULL and rightans!=NULL){
        result->node=root;
        result->hasKeyP=true;
        result->hasKeyQ=true;
    }else if(root->data==p->data){
        result->hasKeyP=true;
        //If q is present in my subtree or not.
        result->hasKeyQ = (leftans)?leftans->hasKeyQ:false or (rightans)?rightans->hasKeyQ:false;
        if(result->hasKeyP and result->hasKeyQ){
            result->node=root;
            return result;
        }
    }else if(root->data==q->data){
        result->hasKeyQ=true;
        //If q is present in my subtree or not.
        result->hasKeyP = (leftans)?leftans->hasKeyQ:false or (rightans)?rightans->hasKeyQ:false;
        if(result->hasKeyP and result->hasKeyQ){
            result->node=root;
            return result;
        }
    }else if(leftans){
        return leftans;
    }else if(rightans){
        return rightans;
    }
    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    Custom* result=helper(root,p,q);
    if(result==NULL){
        return NULL;
    }else{
        return result->node;
    }
}
void print(TreeNode *root){
    if(root==NULL){
        return;
    }
    //Otherwise,print root first followed by subtrees(children)
    cout<<root->data<<" ,";
    print(root->left);
    print(root->right);
}


int main()
{
    TreeNode* root=buildTree();
    TreeNode* head=lowestCommonAncestor(root,8,7);
    cout<<head->data;
}