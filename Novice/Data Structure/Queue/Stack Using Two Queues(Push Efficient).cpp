//Implement Stack Using Two Queue (pushefficient)
//Stack Follows LIFO and Queue Follows FIFO 
/*We can use two Queue one the primary Queue and the seconday queue such that
seconday queue act as a helper for the primary queue*/
/*Push 
It can be done same as enqueue.

Pop
But in stack the element to be poped is most recent element. But in case of 
queue it is least recently element.
So we need to make the least recently to most recently by using seconday array.
Such that we dont lose the element and even get the poping done.
We are going to do this till my size of array is going to be 1. Because size 1 
indicates that the element is the top most element.

All the values are in the secondary array so we can swap the naming of array.
Making the primary array secondary and secondary to primary.
And will perform the operation on the new primary array
*/ 

#include <iostream>
#include<queue>
using namespace std; 
  
class Stack { 
    queue<int> q1, q2; 
    int cs; 
  
public: 
    Stack() 
    { 
        cs = 0; 
    } 
  
    void pop() 
    { 
        if (q1.empty()) 
            return; 
        //Last element is left in the queue.
        while (q1.size() != 1) { 
            q2.push(q1.front()); 
            q1.pop();
        } 
        //The Last element most recent one is removed
        q1.pop(); 
        cs--; 
  
        //The helper queue contains all the element so we swap the name 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void push(int x) 
    { 
        q1.push(x); 
        cs++; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
  
        while (q1.size() != 1) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        // Most recent element of queue is top element of stack 
        int temp = q1.front(); 
        q1.pop(); 
        
        //Last element is pushed
        q2.push(temp); 
  
        // swap the two queues names 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
        return temp; 
    } 
  
    int size() 
    { 
        return cs; 
    } 
}; 
  
int main() 
{ 
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4); 
  
    cout << "current size: " << s.size() 
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    cout << "current size: " << s.size() 
         << endl; 
    return 0; 
} 