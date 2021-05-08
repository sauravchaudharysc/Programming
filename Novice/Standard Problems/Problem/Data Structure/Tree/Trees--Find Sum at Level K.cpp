/*
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output
20
Explanation
Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2
Sum at Level 2 = 3 + 4 + 6 + 7 = 20
*/
#include<bits/stdc++.h>
using namespace std;
 class Node{
   public:
     int data;
     Node *left;
     Node *right;
     Node(int d){
         data=d;
         left=NULL;
         right=NULL;
     }
 };
 
  Node* createTree(Node* root){
    int d;
    cin>>d;
    root=new Node(d);
    int x;
    cin>>x;
    if(x==0){
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(x--){
        root->left=createTree(root->left);
    }
    if(x){
        root->right=createTree(root->right);    
    }
    return root;
 }
 
 
// Function get the sum at nth Level
int sumOfNodesAtNthLevel(Node* root,int k) 
{ 
    if (root == NULL) 
        return 0; 
  
    // Create a Queue 
    queue<Node*> que; 
  
    // Enqueue the root node 
    que.push(root); 
  
    int level = 0; 
  
    // To store the sum of nodes at the Kth level 
    int sum = 0; 
   
    int flag = 0; //To exit when we get the desired level
  
    // Iterate the queue till its not empty 
    while (!que.empty()) { 
  
        // Calculate the number of nodes in the current level 
        int size = que.size(); 
  
        //Enqueue the left and right node of current level
        while (size--) { 
            Node* ptr = que.front(); 
            que.pop(); 
            
            //If desired level is found
            if (level == k) { 
  
                // Flag initialized to 1 break the loop 
                flag = 1; 
  
                // sum of the nodes 
                sum += ptr->data; 
            } 
            else { 
  
                // Traverse to the left child 
                if (ptr->left) 
                    que.push(ptr->left); 
  
                // Traverse to the right child 
                if (ptr->right) 
                    que.push(ptr->right); 
            } 
        } 
  
        //Increase the level by 1
        level++; 
  
        // Break out from the loop after the sum 
        // of nodes at K level is found 
        if (flag == 1) 
            break; 
    } 
    return sum; 
} 
 int main(){
     Node *root1=NULL;
     root1=createTree(root1);
     int k;
     cin>>k;
     cout<<sumOfNodesAtNthLevel(root1,k);
 }