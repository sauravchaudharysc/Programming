#include<iostream>
#include<vector>
using namespace std;

//Implementation Of Generic Stack Data Structure using Vector 
//For all types of Data it can be done using Template
template<typename T>
class Stack{
    private:
        vector<T>v;
        
    public:
        void push(T data){
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
        T top(){
            return v[v.size()-1];
        }
};
int main()
{
    Stack<char> s;
    for(int i=65;i<=70;i++){
        s.push(i);   
    }
    
    //Try to print the content of the stack by poping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}