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

//Insert all the element in tail.
void insertattail(Node *&head,int data)
{
	if(head==NULL){
		head= new Node(data);
		return;
	}

	Node * temp=head;
	 while(temp->next!=NULL)
	 	temp=temp->next;
	temp->next=new Node (data);
	return;
}

//Insert the element in linked list and stops when input is -1
void insertlist(Node *& head) 
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertattail(head,data);
		cin>>data;
	}
}

/*The map::count() is a built-in function in C++ STL which returns 1 if the element with 
key K is present in the map container. It returns 0 if the element with key K is not present
in the container.*/
void print_answer(Node* h){
    map<int,int> m;
    while(h){
        if(m.count(h->data)){
            return;
        }
        else{
            cout<<h->data<<" ";
            m[h->data]=h->data;
        }
        h=h->next;
    }

}

int main(){
    Node *head1=NULL;
    insertlist(head1);
    print_answer(head1);
}