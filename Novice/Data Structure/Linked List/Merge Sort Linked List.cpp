// Merge Sort Linked List
/*
    In Merger Sort
    1. Break the array at mid-point (Divide) . O(1) in array, O(N) in linked list
    2. Recursivlely sort the smaller List. 2T(N/2) || 2T(N/2)
    3. Merge them (Conquer them ). O(N)||)(N)
    
    The Complexity remains same as in array O(NLOGN)
*/ 
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d){
            data=d;
            next=NULL;
        }
        
}; 
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertAtHead(node*&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}

void insertAtTail(node *&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
node* midPoint(node *head){
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
node *merger(node *head1,node *head2)
{
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    node *head;
    if(head1->data < head2->data){
            head=head1;
            head->next=merger(head1->next,head2);
    }else{
            head=head2; 
            head->next=merger(head1,head2->next);
        }
    return head;
}
node *mergeSort(node *head)
{
    //Base Case 
    if(head==NULL || head->next==NULL){
        return head;
    }
//Rec Case
  //1. Mid point 
    node *mid= midPoint(head);
    //1st linked list
    node *a=head;
    //2nd linked list
    node *b=mid->next;
    //Divide the linked list
    mid->next=NULL;
 
  //2.Recursivlely Sort the Linked list   
    a =mergeSort(a);
    b =mergeSort(b);
    
  //3.Merge a and b
   node *c=merger(a,b);
   return c;
}
int main(){
    node *head1,*head2;
    head1=NULL;
    insertAtHead(head1,5);
    insertAtHead(head1,4);
    insertAtHead(head1,3);
    insertAtHead(head1,2);
    insertAtHead(head1,1);
    insertAtHead(head1,11);
    insertAtHead(head1,13);
    print(head1);
    cout<<endl;
    head1=mergeSort(head1);
    print(head1);
} 