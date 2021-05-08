//Linked List
/*Insertion
    -Head
    -Tail
    -Middle*/
/*Insertion in linked list can be done at any point.
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
/*In begining the head is NULL.So at begining when we do n->next=head
It basically points to NULL.The current node n becomes the new head.
Similary when we insert another item.That item next point to the head
And the current item becomes head*/
//To access the data member of pointer we use array.
//Passing a pointer variable by reference.Nor we wont get any output
void insertAtHead(node*&head,int data){
    /*Here the dynamic allocation is used instead of static 
    because i want the node to persist after this call .*/
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

void insertInMiddle(node *&head,int data,int p){
    if(head==NULL || p==0){
        insertAtHead(head,data);
    }else if(p>length(head)){
        insertAtTail(head,data);
    }else{
    node *n=new node(data);
     node *temp=head;
     for(int i=1;i<p;i++){
        temp=temp->next;
     }
     n->next=temp->next;
     temp->next=n;
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
    insertAtTail(head,6);
    insertInMiddle(head,2,3);
    print(head);
}