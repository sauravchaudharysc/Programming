//Stack 
/*It is LIFO Data Structure.
Last In First Out.
Real Life Application :- 
Stack Of Books :- We can pick the books at the top
Atm Machine :- Cash Are Drawn From The Top
*/
/*
Insertion :- To insert element at top
Pop :- To Pop the Top element
Top :- To access the top element
*/
/*Implementation Can Be Done using Linked List , Array , vector
Linked list will be costly traversal at tail.*/

#include<iostream>
#include<vector>
using namespace std;

//Implementation Of Stack Data Structure using Vector 
class Stack{
    private:
        vector<int>v;
    public:
        void push(int data){
            v.push_back(data);
        }
        bool empty(){
            return v.size()==0;
        }
        void pop(){
            if(!empty()){
                v.pop_back();   
            }
        }
        int top(){
            return v[v.size()-1];
        }
};
int main()
{
    Stack s;
    for(int i=1;i<=5;i++){
        s.push(i*i);   
    }
    
    //Try to print the content of the stack by poping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}