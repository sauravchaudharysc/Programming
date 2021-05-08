//Reverse a Linked list
/*Iteratively
  Recursively*/
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        //Constructor for the node
        node(int d){
            data=d;
            next=NULL;
        }
        
}; 
void insertAtHead(node*&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reverse(node *&head){
    node*curr,*prev,*neext;
    curr=head;
    prev=neext=NULL;
    while(curr!=NULL){
        neext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=neext;
    }
    head=prev;
}
//For doing Recursively
/* Base case :- If linked list it has one node. 
   The reverse of linked list will be same.*/
node * reverseRecursive(node *head){
    //Base Case
    if(head->next==NULL || head==NULL){
        return head;
    }
    //Rec head
    node* smallHead=reverseRecursive(head->next);
    node*C = head;
    C->next->next=C;
    C->next=NULL;
    return smallHead;
}   
   
int main(){
    //A pointer which points to the head of linked list
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    cout<<endl;
    reverse(head);
    print(head);
    head=reverseRecursive(head);
    print(head);
}