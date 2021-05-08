/*You are given an array and Q queries of two types.
Type 0: Given a number x , insert the number at the last of the array.
Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y

Input Format
First line of the test case will be the number of queries Q . Then on next Q subsequent lines you will be given a query either of type 0 or type 1. Query of type 0 is of the form : 0 X, where X is the integer to be inserted . Query of type 1 is of the form : 1 L R X

Constraints
0 <= element of array <= 10^9
1 <= N <= 10^5

Output Format
For each query of type 1 output the desired value.

Sample Input
5
0 3 
0 5
0 10 
0 6 
1 1 4 6
Sample Output
10

We can solve this problem using a trie data structure. At each node of the trie, we will store 
the ith bit of the number for a query of type 0. To solve the query of type 1 we will store the
indexes of the number that pass through that node. When we go down the tree during a query and
maximizing the xor, we go in a direction that contains at least one index in range L to R, 
otherwise we ,go in the other direction. To search if at least one index is within the stored
indexes we will use binary search.*/





/*In question we are given two cases:- 
    If zero then we insert the number in the trie
    If one then we get the max xor number for the given range and value
                                    
Insert
We use a trie where we insert all the number given by the user.The number is inserted
in 32 bit format from the LSB.For each value inserted either we got left or right.
    LEFT :-  Zero 
    Right :- One
    
maxXor
We take the value bit from lsb and extract it ith bit each time and check is it either one 
or zero. If we encounter one then we take the trie value zero if possible and for zero we 
take the trie value one if possible . And for every one we take from trie we include that
in our xor value. 

Here we only include the bit in our answer for which trie is one because we need the maximum
value from our vector to get the XOR maximized with the value. 

If the question was to get the maximum XOR value we would include all the value where we got
XOR 1. 
*/
#include<bits/stdc++.h>
using namespace std;

class node {
public :
    node *left;     //Left child node denotes 0 bit
    node *right;    //Right child node denotes 1 bit
    vector <int> v; //Vector to contain all the indices of which this bit is a part of at ith place
    node(){
        left = right = NULL ;
    }
};

class Trie {
private :
    node *root ;
public :
    Trie(){
        root = new node() ;
    }
    //A function to insert the value in trie nodel
    void insert(int n,int index){
        node *temp = root;
        //Insert the value from left most bit.
        for(int i=31 ; i>=0 ; i--){
            int bit = (n >> i) & 1; //Get the ith bit of the given value
            if(bit == 0){
                //0 means node must have a left child to indicate it
                if(temp->left == NULL){
                    temp->left = new node();
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);
                temp = temp->left ;
            }
            else {
                //1 means node must have a right node to indicate it  
                if(temp->right == NULL){
                    temp->right = new node() ;
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);
                temp = temp->right ;
            }
        }
        temp->v.push_back(index);
    }

    int maxXor(int value,int left,int right){
        //Maximise xor with value between index range <left,right>
        int currentXor = 0 ;
        node *temp = root;
        for(int j=31;j>=0;j--){
            //Proceed bit by bit
            int bit = (value >> j)&1;
            //To maximise xor , we need as many opposite bits as possible
            //Move right i.e. towards 1 bit side if value has a 0 bit at jth position
            if(bit == 0){
                //Value has a 0 bit at jth pos 
                //Get a number with 1 bit , move right if there is a right child node between the <left,right> range
                if(temp->right != NULL && binarySearchRange(temp->right->v,left,right)){
                    temp = temp->right ;
                    currentXor += (1<<j) ;  //Add the number with jth bit set to the currentXor
                }
                else {
                    //Else move left
                    temp = temp->left ;
                }
            }
            else {
                //Value has 1 bit at jth pos , move left if possible
                if(temp->left != NULL && binarySearchRange(temp->left->v,left,right)) {
                    temp = temp->left ;
                }
                else {
                    temp = temp->right ;
                    currentXor += (1<<j);   //Add the number with jth bit set to the currentXor
                }
            }
        }
        return currentXor ;
    }

    bool binarySearchRange(vector<int> v,int l,int r){
        //Vector v has indices stored of the numbers of which this bit is a part of 
        //Since the insertion took place in increasing order , vector is already sorted
        int s = 0;
        int e = v.size() - 1;
        while(s <= e){
            int mid = (s+e)/2 ;
            int val = v[mid];
            if(val >= l && val <= r){
                return true ;
            }
            else if(val < l){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false ;
    }
};
int main() {
    int q ;
    cin >> q;
    Trie t;
    int index = 0;
    while(q--){
        int type ;
        cin >> type ;
        if(type == 0){
            //New entry
            int x ;
            cin >> x ;
            t.insert(x,index++);
        }
        else {
            //Query point
            int l,r,x ;
            cin >> l >> r >> x;
            cout << t.maxXor(x,l-1,r-1) << endl;
        }
    }
    return 0;
}