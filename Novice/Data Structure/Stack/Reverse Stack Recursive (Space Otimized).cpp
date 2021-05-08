//Reverese Stack 
//Using Recursion
/*Last Node Ko Bahar Nikalunga aur recusrion ko bolunga baki ko tu reverse karke aa*/
//Last Node will be insertedAtBottom
/*
Insert At Bottom 
If empty then simply push
otherwise pop and call insert at bottom.Then push the poped element*/
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(y); 
}
void revereseStackRec(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    revereseStackRec(s);
    insertAtBottom(s,x);
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    revereseStackRec(s1);
    while(!s1.empty()){
        cout<<s1.top()<<" -->";
        s1.pop();
    }
    return 0;
}