//Overload Right shift and Left Shift operator
//Suppose you want to take input and get output of linked using cin and cout
// Left shift and right shift are of istream and ostream class and head of node class
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
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void createList(node *&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}
//Head is passed by reference to get change in real head
istream& operator>>(istream &is,node*&head){
    createList(head);
    return is;
}
ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    cin>>head1>>head2;
    cout<<head1<<endl<<head2;
}