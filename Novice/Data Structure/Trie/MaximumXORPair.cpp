//Maximum Xor Pair Value.
//Brute Force :- Calculate all the possible pair and calulate the X0R O(n^2).
//XOR of two numbers. If both are 0 or 1 then output is zero.
//As many one's from MSB to LSB in binary reprsentation
//We will have left child and right child
//Left denoting the instance of zero and right denoting the instance of one
#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
        trieNode *left;  //Represent 0
        trieNode *right; //Represent 1
};

//This function creates the trie structure of all the input number
void insert(int n,trieNode *head){
    trieNode *curr = head;
    //What ever will be the input of integer at max it will have 32 bit
    for(int i=31; i>=0;i--){
        int bit=(n>>i)&1;
        if(bit==0){
            if(curr->left==NULL){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }else{
                if(curr->right==NULL){
                    curr->right=new trieNode();
                }
              curr=curr->right;    
            }
    }
}

int findMaxXorPair(trieNode *head,int *arr,int n,int element){
    int max_xor=INT_MIN;
    trieNode *curr=head;
    int value=element;
    int curr_xor=0;
    for(int j = 31; j>=0; j--){
        int b = (value >> j) & 1;
        if(b == 0){
            //current bit is 0
            if(curr->right!=NULL){
                //if any right child is present
                curr=curr->right;
                curr_xor+=(int)pow(2,j);
            }else{
                //if no right child is present
                  curr=curr->left;
                } 
        }else{
            //current bit is 1
            if(curr->left!=NULL){
                //if any left child is present
                curr=curr->left;
                curr_xor+=(int)pow(2,j);
            }else{
                //if no left child is present
                  curr=curr->right;
                } 
        }   
    }
    if(curr_xor>max_xor){
        max_xor=curr_xor;
    }
        return max_xor;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trieNode *head=new trieNode();
    int result=INT_MIN;
    for(int i=0;i<n;i++){
        insert(arr[i],head);
        //For each insertion we will compare it with out trie structure
        int x=findMaxXorPair(head,arr,n,arr[i]);
        result=(result<x)?x:result;
    }
    cout<<result<<endl;
}

//Time Complexity :- At max we can go to the maximum depth.So 32 steps is taken and since there are n value. So it will be O(N)