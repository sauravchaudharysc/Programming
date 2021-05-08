//Insertion Sort 

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int d)
	{
		data=d;
		next=NULL;
	}
};

void push(Node*&head,int x){
    if(head==NULL){
		head= new Node(x);
		return;
	}

	Node * temp=head;
	 while(temp->next!=NULL)
	 	temp=temp->next;
	temp->next=new Node (x);
	return;

}

void sortedInsert(Node *&current,Node *&sorted){
    if((sorted==NULL)||sorted->data>=current->data){
        current->next=sorted;
        sorted = current;
    }else{
        Node *p=sorted;
        while(p->next!=NULL && p->next->data < current->data){
            p=p->next;
        }
        current->next=p->next;
        p->next=current;
    }
    
}

void insertion_Sort(Node *&head){
    Node *sorted = NULL;
    Node *current = head;
    while(current != NULL){
        Node* next=current->next;
        sortedInsert(current,sorted);
        current=next;
    }
    head=sorted;
}

void print_answer(Node* h){
    while(h){
        cout<<h->data<<" ";
        h=h->next;
    }
    cout<<endl;
}

int main(){
    Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        push(head,x);
    }
    insertion_Sort(head);
    print_answer(head);
}