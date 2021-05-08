/*Floyd's Cycle Detetion.
Take two pointer slow and fast. Fast moves 2 step ahead and slow moves
one step. So at a point when both the fast and slow pointer points to same
node then there is a cycle and if fast reaches NULL then there is no cycle
since linked list turns out to be empty*/
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
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

bool cycleDetection(node *head){
    node *slow,*fast;
    slow=fast=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
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
    if(cycleDetection(head)){
        cout<<"Cycle Present";
    }else{
        cout<<"No Cyle Present";
    }
}