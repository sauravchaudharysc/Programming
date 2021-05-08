#include<bits/stdc++.h>
using namespace std;

//Declare a node for each tree 
class Node{
  public:
    int data;
    int index;
    Node *left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void verticalOrderPrint(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    map<int,vector<int>>m;
    int index=0;
    root->index=0;
    q.push(root);
    /*A queue is used for level order traversal*/
    while(q.size()){
        index=root->index;
        //Push the node index wise and 
        m[index].push_back(root->data);
        
        //On going left from root do -1 
        if(root->left){
            root->left->index=index-1;
            q.push(root->left);
        }
        
        //On going right from root do +1
        if(root->right){
            root->right->index=index+1;
            q.push(root->right);
        }
        //Pop the explored node
        q.pop();
        //Initialise the node in queue as current node
        root=q.front();
    }
    for (auto it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    }  
}
Node* createTree(Node* root){
    int level;
    cin>>level;
    int d;
    cin>>d;

    root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        Node *f = q.front();
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
    verticalOrderPrint(root);
    cout<<endl;
}