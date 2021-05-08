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
    cout<<endl;
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
node* merger(node *head1,node *head2)
{
    node *head=NULL;


    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data >head2->data)
        {
            insertAtTail(head,head2->data);
            
           
            head2=head2->next;

        }
        else if(head1->data <head2->data)
        {
            insertAtTail(head,head1->data);
            
            head1=head1->next;
           
        }
    }
    while(head1 != NULL)
    {
        
        insertAtTail(head,head1->data);
        
        head1=head1->next;
    }
    while(head2 != NULL)
    {
        
        insertAtTail(head,head2->data);
        head2=head2->next;
    }
    return head;
}
int main(){
    node *head,*head1,*head2;
    head1=NULL;
    head2=NULL;
    head=NULL;
    insertAtHead(head2,5);
    insertAtHead(head2,5);
    insertAtHead(head2,5);
    
    insertAtHead(head1,4);
    insertAtHead(head1,4);
    insertAtHead(head1,4);
    
    head = merger(head1,head2);
    print(head);
}