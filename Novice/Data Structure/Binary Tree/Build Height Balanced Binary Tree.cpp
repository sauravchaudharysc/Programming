//Build height Balanced Tree
//Balance tree has a height of logn
/*
Difference of height in left subtree and right tree must be less than equal to one.
|h1-h2|<=1.

For this we need to break the array at the middle.Left Side of array will be part of 
left subtree and Right side of the array will be a part of right subtree.And Call them
recursively do the same find the midpoint make it root node and divide them in left 
 and right.
 
 Base case 
    start > end return NULL;
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
void bfs(node *root){
    //I need the node in queue to contain it address
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *f= q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
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
node* buildTreeFromArray(int *a,int s,int e){
    //Base Case 
    if(s>e){
        return NULL;
    }
    //Recursive Case 
    int mid = (s+e)/2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
}
int main(){ 
    int a[]={1,2,3,4,5,6,7};
    int n=7;
    node *root = buildTreeFromArray(a,0,n-1);
    bfs(root);
}