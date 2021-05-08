/*Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. Print 0 if no such node exist at distance k.

Input Format
The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT. The next line will contain an integer T. Then T lines follow you will be given 2 integers the first one denoting the value of Node and the second one denoting the value of k.

Constraints
2 ≤ N ≤ 10^3

Output Format
On T lines print space separated desired output for each test case in sorted form

Sample Input
4
60 65 50 70
50 65 60 70
2
60 1
65 2
Sample Output
65 70
70
Explanation
The tree looks like

             60
          /      \
       65         70
     /
  50
For testcase 1 : The nodes 65 and 70 are the only ones at distance k=1 from 60.
For testcase 2 : The node 70 is at distance k=2 from 65.*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

//A vector to get the element pushed 
vector<int>v1;

//To print the kth node below the target
void knodeBelow(node *root, int k) 
{ 
    // Base Case 
    if (root == NULL || k < 0)  return; 
  
    // If we reach a k distant node, print it 
    if (k==0) 
    { 
         v1.push_back(root->data);
        return;
    } 
 
    knodeBelow(root->left, k-1); 
    knodeBelow(root->right, k-1); 
} 


int knode(node *root,int target,int k)
{
    if(root==NULL)
        return -1;
    if(root->data==target){
        knodeBelow(root,k);
        return 0;
    }
    int dl=knode(root->left,target,k);
    //dl becomes zero when target node is found
    if(dl!=-1){
        //If k is just above it then because as we return from target node we are just above it
        if(dl+1==k){
            v1.push_back(root->data);
        }else{
            //As we were above the target going right means travelling 2 nodes
            knodeBelow(root->right,k-dl-2);
        }
        return dl+1;
    }
    
    int dr=knode(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            v1.push_back(root->data);
        }else{
            knodeBelow(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int d1=0;
node *createTree(int inOrder[],int preOrder[],int b1,int b2){
    if(b2<b1){
        return NULL;
    }
    int k= preOrder[d1++];
    node *root= new node(k);
    int l=b1;
    while(inOrder[l]!=k){
        l+=1;
    }
    root->left=createTree(inOrder,preOrder,b1,l-1);
    root->right=createTree(inOrder,preOrder,l+1,b2);
    return root;
}
int main(){
    int n2;
    cin>>n2;
    int preOrder[n2];
    for(int i=0;i<n2;i++){
        cin>>preOrder[i];
     }
    int inOrder[n2];
    for(int i=0;i<n2;i++){
        cin>>inOrder[i];
    }
    node* root=createTree(inOrder,preOrder,0,n2-1);
    int q;
    cin>>q;
    while(q--){
        int x,k;
        cin>>x>>k;
        knode(root,x,k);
        if(v1.size()==0){
            cout<<"0";
        }else{
            sort(v1.begin(),v1.end());
            for(auto i:v1){
                cout<<i<<" ";
            }
        }
        v1.clear();
        cout<<endl;
    }
}