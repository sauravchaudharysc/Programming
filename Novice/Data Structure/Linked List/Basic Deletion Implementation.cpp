//Linked List
/*Deletion
    -Head
    -Tail
    -Middle*/
/*Deletion in linked list can be also done at any point.
Deletion means to free up the memory not to just shift pointer
Not as array insertion at last is only possible*/
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

int length(node* head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
    return;
}
void deletAtTail(node *&head){
    if(head==NULL){
        return;
    }
    node *tail=head,*prev;
    while(tail->next!=NULL){
        prev=tail;
        tail=tail->next;
    }
    delete tail;
    prev->next=NULL;
    return;
}

void deleteInMiddle(node *&head,int p){
    if(head==NULL){
    return;
    }else if(p==length(head)){
        deletAtTail(head);
        return;
    }else if(p==1){
        deleteAtHead(head);
        return;
    }else{
    node *temp=head,*prev;
     for(int i=1;i<p;i++){
         prev=temp;
        temp=temp->next;
     }
     prev->next=temp->next;
     delete temp;
     return;
    }
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    //A pointer which points to the head of linked list
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    deletAtTail(head);
    deleteAtHead(head);
    print(head);
    deleteInMiddle(head,3);
    cout<<endl;
    print(head);
}