#include<bits/stdc++.h>
using namespace std;
//liss is stored in case of dp. the value of smaller subproblem is saved and returned on call
class node{
    public:
    int data;
    int liss;
    node *left, *right;
};

int LISS(node *root)  
{  
    if (root == NULL)  
    return 0;
    /*If we exclude the current node then we can take
     both left and right child in the set*/
    int size_excl = LISS(root->left) +  
                    LISS(root->right); 
    /*If we include the current node then we cant take
     both left and right child in the set. 
     For this:- 
               (i)left:-root->left->left
               (ii)right:-root->left->right
               size=1+left+right*/                
    int size_incl = 1;  
    if (root->left)  
        size_incl += LISS(root->left->left)+LISS(root->left->right);  
    if (root->right)  
        size_incl += LISS(root->right->left)+LISS(root->right->right);                
    return max(size_incl, size_excl);
}
int LISSDP(node *root)  
{  
    if (root == NULL)  
        return 0;  
  
    if (root->liss)  
        return root->liss;  
  
    if (root->left == NULL && root->right == NULL)  
        return (root->liss = 1);  
  
    // Calculate size excluding the current node  
    int liss_excl = LISSDP(root->left) + LISSDP(root->right);  
  
    // Calculate size including the current node  
    int liss_incl = 1;  
    if (root->left)  
        liss_incl += LISSDP(root->left->left) + LISSDP(root->left->right);  
    if (root->right)  
        liss_incl += LISSDP(root->right->left) + LISSDP(root->right->right);  
  
    // Maximum of two sizes is LISS, store it for future uses.  
    root->liss = max(liss_incl, liss_excl);  
  
    return root->liss;  
}  
node* newNode(int data)  
{  
    node* temp = new node();  
    temp->data = data;  
    temp->left = temp->right = NULL;  
    temp->liss = 0;  
    return temp;  
}  
int main()
{
    /*
    The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.
        20
       /  \
      8    22
     / \    \
    4  12    25
      /  \
     10   14
     */
     
    node *root = newNode(20);  
    root->left = newNode(8);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    root->right = newNode(22);  
    root->right->right = newNode(25);  
  
    cout << "Size of the Largest" 
         << " Independent Set is " 
         << LISS(root)<<endl;
    
    cout << "Size of the Largest" 
         << " Independent Set is " 
         << LISSDP(root);
}