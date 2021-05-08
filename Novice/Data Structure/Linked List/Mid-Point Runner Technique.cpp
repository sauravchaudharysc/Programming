//Mid Point of the linked list
/*
Easiest approach :- The easiest approach would be to find the length of 
the linked list and use the iterator and reach the mid-length*/
/*Better Aprroach:- 
Runner Technique 
Suppose there are two swimmers one who swims with speed of 2x and one 
with x.So one who swims with 2x will reach end and one with x will be at mid.
*/
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
node* mid(node *head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    node* slow=head;
    node* fast=head->next;
    //And is used if any of them reaches NULL means the linked list is empty
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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
    node *m = mid(head);
    cout<<m->data;
} 