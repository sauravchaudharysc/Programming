//Balance Paranthesis
//We can use Stack LIFO Property to check balanced Paranthesis
/*
Algorithm
Every opening brack encounter and push into stack.
For Every closing bracket enocuntered pop out of the stack.
If string is fully traversed stack is empty then balanced*/
#include<bits/stdc++.h> 
using namespace std; 
  
bool areParanthesisBalanced(string expr) 
{ 
    stack<char> s; 
    char x; 
  
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            s.push(expr[i]); 
            continue; 
        } 
  
        //If current character is not opening bracket then it must be a closing one
        //So if stack is empty then return false. Because there is no opening bracket
        //present for a closing one.
        //so we need to pop and opening from stack. If stack is empty then it is 
        if (s.empty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')': 
  
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 
    } 
    return (s.empty()); 
} 
int main() 
{ 
    string expr = "{()}[]"; 
  
    if (areParanthesisBalanced(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
} 