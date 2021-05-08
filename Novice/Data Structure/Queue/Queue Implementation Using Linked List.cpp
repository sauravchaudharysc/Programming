//Linked list Based
#include<iostream>
#include<list>
using namespace std;
class Queue{
        list<int> queue;
        int cs; //current size
        
    public:    
       Queue(int default_size =7){
         this->cs=0;
       }
       
       //no need of this because our list becomes the size always evergreen
    //   bool isFull(){
    //       return this->cs==this->ms;
    //   }
       bool isEmpty(){
           return this->cs == 0;
       }
       void enqueue(int data){
               this->queue.push_back(data);
               this->cs+=1;
       }
       void dequeue(){
           if(!isEmpty()){
               this->queue.pop_front();
               this->cs-=1;
           }
       }
       int getFront(){
           return this->queue.front();
       }
};


int main()
{
    Queue q(10);
    for(int i=1;i<=6;i++){
        q.enqueue(i);
    }
    q.dequeue();
    q.enqueue(8);
    while(!q.isEmpty()){
        cout<<q.getFront()<<endl;
        q.dequeue();
    }
    return 0;
}