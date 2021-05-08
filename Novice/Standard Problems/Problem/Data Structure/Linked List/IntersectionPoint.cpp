#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

Node* push(Node *head,int x){
    
    Node *newNode=new Node();
    newNode->data=x;
    newNode->next=NULL;
    if(head==NULL){
        return newNode;
    }else{
        Node *p =head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newNode;
        return head;
    }
}

int interSection(Node *root1,Node *root2,int d){
    Node *p=root1;
    Node *q=root2;
    while(d--){
        p=p->next;
    }
    while(p!=NULL && q!=NULL){
        if(p->data==q->data){
            return p->data;
        }
        p=p->next;
        q=q->next;
    }
    return -1;
}
int main(){
    Node *root1,*root2;
    root1=NULL;
    root2=NULL;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        root1=push(root1,x);
    }
    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        root2=push(root2,x);
    }
    int d=abs(n1-n2);
    int ans;
    if(n1>n2){
     ans=interSection(root1,root2,d);    
    }else{
     ans=interSection(root2,root1,d);    
    }
    cout<<ans<<endl;
}