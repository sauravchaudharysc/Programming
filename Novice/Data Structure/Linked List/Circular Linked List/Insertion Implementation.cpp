//Circular Linked List
/*In single linked list the structure consist of data and next pointer.In single
linked list last node next points to NULL but in case of circular linked list there
is a minor difference the last node next points to head.

Circular Linked List Tails Point to Head.

Application
1.Many Cpu Algorithms
2. Queue Operation
3. Fibonnaci Algorithms*/

//Traversal And Insertion In Circular Linked List
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        
        //Constructor
        Node(int data){
            this->data=data;
        }
};

void insertHead(Node *&head,int data)
{
    Node *n=new Node(data);
    n->next=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return ;
    }else{
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        head=n;
    }
}
void insertTail(Node *&head,int data)
{
    Node *n=new Node(data);
    n->next=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return ;
    }else{
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
    }
}
void print(Node *head)
{
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
    Node *head=NULL;
    insertHead(head,6);
    insertHead(head,5);
    insertHead(head,4);
    insertHead(head,3);
    insertTail(head,10);
    insertTail(head,11);
    insertTail(head,12);
    insertTail(head,13);
    insertTail(head,14);
    print(head);
}