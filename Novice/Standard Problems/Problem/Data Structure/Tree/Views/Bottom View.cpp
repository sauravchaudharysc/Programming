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
    /*A queue is initialised to print the tree level wise in order .
    Travelling level wise means travelling level from top to bottom 
    following direction left to right.
    */
    queue<Node*>q;
    map<int,int>m;
    int index=0;
    /*Initialise each node a index and Initialise a map such that each 
    horizontal column denote only a single value.Each time you find a value
    replace the value in map so that you get the last most updated value.*/
    root->index=0;
    q.push(root);
    while(q.size()){
        index=root->index;
        //Store the value or update if present before
        m[index]=root->data;
        
        //We initalise the left of root index as index-1
        if(root->left){
            root->left->index=index-1;
            q.push(root->left);
        }
        
        //We initalise the right of root index as index+1
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