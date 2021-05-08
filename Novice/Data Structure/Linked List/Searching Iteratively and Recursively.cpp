//Linked List
/*Searching
Recursive And Iterative*/
/*I iterate over the nodes and when i see the node having data i am searching for
i return the address or boolean value.And if i reach end then it isnt present. And 
using recursion i do for one node and if not found in that node i let recusrion 
search forward and if found then returnthe address or boolean and if linked List
get empty then element isnt present*/
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

bool searchRecursive(node *head,int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }else{
        return searchRecursive(head->next,key);
    }
     
}

bool searchIterative(node *head,int key){
    int len=length(head);
    for(int i=0;i<len;i++){
        if(head->data==key){
            return true;
        }
        head=head->next;
    }
    return false;
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
    if(searchRecursive(head,2)){
        cout<<"present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    print(head);
}