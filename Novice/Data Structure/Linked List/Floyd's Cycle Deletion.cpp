/*Floyd's Cycle Deletion.
Take two pointer slow and fast. Fast moves 2 step ahead and slow moves
one step. So at a point when both the fast and slow pointer points to same
node then there is a cycle . After this just move the slow pointer to the head
and fast pointer remains at same position. Move slow and fast one step and compare
if fast>next=slow then break the link and point it to NULL*/

/*
A Better Approach same as Floyd cycle deletion but adding an additional feature of 
Kth node. Detect the loop Using Floyd Cycle Detection then find the length of loop.
Take two pointers one to head and one to the kth position. Then move 
both pointers simulataneously.When they meet at a node that is the starting node.
Get a pointer to the last node of the loop and make it next NULL.*/
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void print(node *head)
{
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void removal(node *fast,node *head)
{
    node *slow=head;
    while(fast!=slow){
        slow=slow->next;
        if(fast->next==slow){
            fast->next=NULL;
            break;
        }
        fast=fast->next;
    }
}
bool cycleDetectionAndRemoval(node *head){
    node *slow,*fast;
    slow=fast=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            removal(fast,head);
            return true;
        }
    }
    return false;
}
int main()
{
    node* head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    head->next->next->next->next->next=new node(6);
    head->next->next->next->next->next->next=new node(7);
    //Last node is linked with the third node
    head->next->next->next->next->next->next->next=head->next->next;
    if(cycleDetectionAndRemoval(head)){
        print(head);
    }else{
        cout<<"Not valid";
    }
}