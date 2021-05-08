//Nodes at Distance K in Binary Tree 
/*
All the nodes at distance K will be at 2 kind of position only.
Either all the nodes at distance k will be at subtree rooted at the target.
Or the subtree of any ancestor of target.

So all possible ancestor are required to be considered. 

For any node,if target is in the LST,look for all node from me(root/node)
at a distance k-l-1(RST).

For any node if target is in the RST at distance R+1 look for all node from me(root/node)
at distance k-R-1
*/
 
 /*
 Pseudo Code 
 vector<int>result;
 int recurse(Treenode *root,int k){
     if(root==NULL)
     {
         return -1;
     }else if(root == target){
         percolatedown(root,k);
         return 1;
     }else{
         int l=recurse(root->left);
         int R=recurse(root->right);
         if(l!=1){
           if(l==k){
               result.pb(root.val);
               percolatedown(root,k-l-1);
               return l+1;
           }else if(R!=1){
               
            }
         }else{
             return -1;
         }
     }
 } 
 */