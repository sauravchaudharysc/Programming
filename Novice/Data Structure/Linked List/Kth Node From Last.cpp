//Kth Node From the last of linked list

/*Easiest Aprroach you can find the length of linked list. And then you can
iterate l-k times.*/
/*SIngle Pass Approach(Similar to Runner Technique)
Make Fast Pointer Jump K Steps Forward.
Then after that move slow and fast simultaneously.
So When fast reaches n,slow reaches n-k the desired position*/
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
node * Kth(node *head,int k)
{
    node *fast=head;
    node *slow=head;
    while(k!=0){
        fast=fast->next;
        k--;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
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
    node *k=Kth(head,3);
    cout<<k->data;
} 