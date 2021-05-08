/*Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2
Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Node{
    public:
    ll data;
    Node *next;
};

//To push a node in linked list
Node *push(Node *head,ll num){
    Node *newNode = new Node();
    newNode->data=num;
    newNode->next=NULL;
    if(head==NULL){
        return newNode;
    }else{
        Node *p = head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newNode;
    }
    return head;
}

//TO reverse a linked list upto k
Node *reverse(Node *head,ll k){
    Node* current = head;
    Node* prev = NULL;
    Node* neext = NULL;
    ll count=0;
    while(current!=NULL && count<k){
        neext = current->next;
        current->next = prev;
        prev = current;
        current = neext;
        count++;
    }
    if(neext!=NULL){
        head->next=reverse(neext,k);
    }
    return prev;
}

//To print the linked list
void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
} 

int main(){
    Node *root=NULL;
    ll n,x;
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        ll num;
        cin>>num;
        root=push(root,num);
    }
    root=reverse(root,x);
    printList(root);
}