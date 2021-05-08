/*
To reverse a stack without using extra space.
Suppose you push number 1 2 3 in stack . So to reverse this means in stack there should 
be 3 2 1.So that when you print the stack you get 1 2 3.

So we make a reverse stack function. And store the top and make a recursive call for the rest
of stack and do this until the stack turns out to be empty.

We make a helper function we push all the incoming element at bottom. 
So for single element it is simply pushed and rest element.We remove all the element recursively
and push the incoming element.So the stack get reversed

*/
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int ch){
    if(s.empty()){
        s.push(ch);
        return;    
    }
    int y=s.top();
    s.pop();
    insertAtBottom(s,ch);
    s.push(y);
}
void reverse_Stack(stack<int>&s){
    if(s.empty()){
        return;
    }else{
        int ch=s.top();
        s.pop();
        reverse_Stack(s);
        insertAtBottom(s,ch);
    }
}
int main(){
    stack<int>S1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        S1.push(x);
    }
    reverse_Stack(S1);
    while(!S1.empty()){
        cout<<S1.top()<<endl;
        S1.pop();
    }
}