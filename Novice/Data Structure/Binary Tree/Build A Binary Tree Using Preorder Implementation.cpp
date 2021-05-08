//Build A Binary Tree Using the Preorder Traversal
//Input :- 10 20 5 -1 -1 9 3 -1 -1 -1 2 -1 6 -1 8 -1 -1
/*My root will be processed first then my left subtree will be processed and at last
right subtree will be processed

The first node will be the root , some range after root will be my nodes of left
sub tree and after that range the nodes will of right subtree.

int d;
cin>>d; 
if(d==-1*{
return NULL;
}
root =new Node(d);
root->left=buildtree(root->left);
root->right=buiodtree(root->right);
return root;*/

#include<iostream>
#include<queue>
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
};

TreeNode* buildUsingPre(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }  
    TreeNode *root=new TreeNode(d);
    root->left=buildUsingPre();
    root->right=buildUsingPre();
    return root;
}
void bfs(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
int main()
{
    TreeNode *root=buildUsingPre();
    bfs(root);
}
