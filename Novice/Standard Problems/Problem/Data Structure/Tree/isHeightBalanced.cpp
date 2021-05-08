/*Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
1 <= No of nodes <= 10^5

Output Format
Display the Boolean result

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
true
Explanation
The tree looks like

             10
          /       \
       20           30
    /     \       /     \
   40      50    60      73
The given tree is clearly balanced as depths of the left and right sub-trees of every node differ by 1 or less.
*/
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

pair<int,bool> isHeightBalancedOptimised(Node *root){
    if(!root){
        return make_pair(0,true);
    }
    pair<int,bool>l,r;
    l=isHeightBalancedOptimised(root->left);
    r=isHeightBalancedOptimised(root->right);
    int x=(l>r)?(l.first+1):(r.first+1);
    if(l.second && r.second){
        bool y=(abs(l.first-r.first)<=1);
        return make_pair(x,y);
    }
    return make_pair(x,false);
}

int main()
{
    Node *root = createTree("true");

    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}