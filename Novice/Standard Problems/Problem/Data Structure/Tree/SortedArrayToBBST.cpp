/*You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

Input Format
First line contains integer t as number of test cases.
Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers denoting the elements for the BST.

Constraints
1 < t < 100
1< n < 1000

Output Format
For each testcase , print the preorder traversal of the BST in a new line.

Sample Input
1
7
1 2 3 4 5 6 7
Sample Output
4 2 1 3 6 5 7
Explanation
The tree looks like

             4
          /      \
       2           6
    /     \      /    \
   1       3    5      7
We print the preorder of the final tree.*/

/*
Algorithm
1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
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

Node* bst(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    
    int mid = (start+end)/2;
    Node *root=new Node(arr[mid]);
    root->left=bst(arr,start,mid-1);
    root->right=bst(arr,mid+1,end);
    return root;
}

void preOrder(Node* node)  
{  
    if (node == NULL)  
        return;  
    cout << node->data << " ";  
    preOrder(node->left);  
    preOrder(node->right);  
}  

int main(){
    int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Node *root=bst(arr,0,n-1);
        preOrder(root);
		cout<<"\n";
	}	
}