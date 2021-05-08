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
//Same as printlist and yes do while loop can be also used 
//to avoid extra statement of last node
Node* getNode(Node *&head,int data){
    Node* temp=head;
    while(temp->next !=head){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){
        return temp;
    }
    else{
        return NULL;
    }
}

//Two cases arises
/*1.If get node is NULl then that element is not present.
2.If get node returns head then we will traverse the whole list and when we reach
end we will make it to point head->next;
3.If lies anywhere between the linked list. We will traverse the node with temp.
If temp->next points to get node. We will store temp->next and then
temp->next=temp->next->next. Then free the stored temp->next*/

void deleteNode(Node *&head,int data){
    Node *del=getNode(head,data);
    if(del==NULL){
        cout<<"Node isnt present in linked list"<<endl;
    }
    if(head==del){
        head=del->next;
    }
    Node *temp=head;
    while(temp->next!=del){
        temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}
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
    deleteNode(head,12);
    print(head);
}