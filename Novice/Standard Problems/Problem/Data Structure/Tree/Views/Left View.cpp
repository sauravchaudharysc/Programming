/*Given a binary tree , print its nodes from root to bottom as visible from left side of tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the left view of the tree

Sample Input
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output
1 2 4
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \           \
   4       5           6
When viewed from the left , we would see the nodes 1,2 and 4.*/
#include<bits/stdc++.h>
using namespace std;

//Declared a Node for each tree
class Node{
    public:
        int data;
        int index;
        Node* left;
        Node* right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

//Function to print top view of a tree
void topview(Node* root){
    if(root==NULL){
        return;
    }
    /*A queue is initialised to print the tree level wise in order to 
      print the top node at first.As the first node at each level is vistied
      at first.So we use this idea to print the left node of each level
    */
    queue<Node*>q;
    map<int,int>m;
    int index=0;
    /*Initialise each node a index. So that the first node of each level marked and
      is printed first*/
    root->index=0;
    q.push(root);
    while(q.size()){
        index=root->index;
        //m.count returns is there the index element present already
        if(m.count(index)==0){
            m[index]=root->data;
        }
        //Each level is given a index
        if(root->left){
            root->left->index=index+1;
            q.push(root->left);
        }
        
        if(root->right){
            root->right->index=index+1;
            q.push(root->right);
        }
        //Pop the top most node and explore the next node
        q.pop();
        //Initialise the current node as root
        root=q.front();
    }
     for(auto i=m.begin();i!=m.end();i++) 
    { 
        cout<<(i->second)<<" "; 
    } 
}



Node* createTree(Node* root){
    int d;
    cin>>d;

    root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        Node*f = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            f->left = new Node(c1);
            q.push(f->left);
        }
        if(c2!=-1){
            f->right = new Node(c2);
            q.push(f->right);
        }
    }
 return root;
}
 
int main(){
    Node *root=NULL;
    root=createTree(root);
    topview(root);
    cout<<endl;
}