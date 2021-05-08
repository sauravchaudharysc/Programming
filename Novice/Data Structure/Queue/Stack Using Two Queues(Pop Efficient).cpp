//Implement Stack Using Two Queue (Pop efficient)
//Stack Follows LIFO and Queue Follows FIFO 
/*We can use two Queue one the primary Queue and the seconday queue such that
seconday queue act as a helper for the primary queue*/
/*Queue can pop element from front only.
So to ensure pop efficient Stacl using queue. The element to be poped is present
at front .

Pop 
When we dequeue the element dequed will be the most recent element.For this we can
have some Implementation in our push operation

Push 
Logic :- Secondary Array Is Always ampty while inserting new element.

We take two array primary and Secondary. We enqueue an element in secondary array.
Check is primary array empty. If yes we change the name.
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
  void push(int x) 
    { 
        cs++; 
  
        // Push x first in empty q2 
        q2.push(x); 
  
        // Push all the remaining 
        // elements in q1 to q2. 
        while (!q1.empty()) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        // swap the names of two queues 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void pop() 
    { 
        if (q1.empty()) 
            return; 
        q1.pop(); 
        cs--; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
        return q1.front(); 
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