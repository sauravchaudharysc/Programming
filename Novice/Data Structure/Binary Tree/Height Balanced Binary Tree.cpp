//Height Balanced Tree
/*
Difference of height in left subtree and right tree must be less than equal to one.
|h1-h2|<=1
*/

#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
class HBPair{
    public:
        int height;
        bool balance;
};

HBPair isHeightBalance(node *root){
    HBPair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    //Recursive case
    HBPair left = isHeightBalance(root->left);
    HBPair right= isHeightBalance(root->right);
    
    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.height = max(left.height,right.height)+1;
    }
    return p;
}
int main(){ 
    node* root = buildTree();
    if(isHeightBalance(root).balance){
        cout<<"Balanced ";
    }else{
        cout<<"Not Balanced";
    }
      return 0;
}