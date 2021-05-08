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
node *merger(node *head1,node *head2)
{
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    node *c;
    if(head1->data < head2->data){
            c=head1;
            c->next=merger(head1->next,head2);
    }else{
            c=head2; 
            c->next=merger(head1,head2->next);
        }
    return c;
}
int main(){
    node *head1,*head2;
    head1=NULL;
    head2=NULL;
    insertAtHead(head2,5);
    insertAtHead(head2,4);
    insertAtHead(head2,3);
    insertAtHead(head2,2);
    insertAtHead(head2,1);
    insertAtHead(head1,5);
    insertAtHead(head1,4);
    insertAtHead(head1,3);
    insertAtHead(head1,2);
    insertAtHead(head1,1);
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;
    head1=merger(head1,head2);
    print(head1);
} 