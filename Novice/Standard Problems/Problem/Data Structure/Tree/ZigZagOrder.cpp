/*Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left. Each level should be printed at a new line.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Display the values in zigzag level order in which each value is separated by a space

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
10 30 20 40 50 60 73 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

Node *createTree(string s){
    if(s=="true"){
        int d;
        cin>>d;
        Node* root=new Node(d);
        string l;
        cin>>l;
        if(l=="true"){
            root->left=createTree(l);
        }
        string r;
        cin>>r;
        if(r=="true"){
            root->right=createTree(r);
        }
        return root;
    }
    return NULL;
}

int getHeight(Node *root){
    if(root==NULL){
        return 0;
    }else{
        int lheight=getHeight(root->left);
        int rheight=getHeight(root->right);
        return (lheight>rheight)?(lheight+1):(rheight+1);
    }
}

void printGivenLevelLeft(Node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevelLeft(root->left, level-1);  
        printGivenLevelLeft(root->right, level-1);  
    }  
}  

void printGivenLevelRight(Node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevelRight(root->right, level-1);  
        printGivenLevelRight(root->left, level-1);  
    }  
}  

void printLevelOrder(Node *root){
    int h=getHeight(root);
    for(int i=1;i<=h;i++){
        if(i&1){
                printGivenLevelLeft(root,i);
        }else{
                printGivenLevelRight(root,i);
        }   
    
    }
}

int main()
{
    Node *root = createTree("true");

    printLevelOrder(root);
    cout<<endl;

    return 0;
}