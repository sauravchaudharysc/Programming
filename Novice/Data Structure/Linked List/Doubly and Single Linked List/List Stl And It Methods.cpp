//List
/*A list stl in C++ corresponds to doubly linked list. A linked list is a linear data structure
but memory is not contiguous.And doubly linked is same as linked.But in this we can move in 
both direction.

Application:-
Insertion and deletion of the element from middle is easier 

Four important Methods
push_back() :- Insert at tail
push_front() :- Insert at head
pop_front() :- Remove at front 
pop_back() :- Remove at head 
*/
#include<iostream>
#include<list>
using namespace std;
int main(){
    //To declare list 
    list<int>l;
    list<int>l1{2,3,10,8,5};
    //Different datatype
    list<string>l2{"Apple","Guava","Mango"};
    l2.push_back("Pineapple");
    //Inbuilt Sort Method Of List class
    l2.sort();
    
    //Inbuilt Reverese Method Of List class
    l2.reverse();
    
    //To See the front element
    cout<<l2.front()<<endl;
    
    //To remove the front element
    l2.pop_front();
    
    //To See the last element
    cout<<l2.back()<<endl;
    
    //To remove the last element
    l2.pop_back();
    
    //To add to the first of List
    l2.push_front("Kiwi");
    
    //Iterate using for loop
    //begin points to first node of the list and end points to last node of list
    for(auto it=l2.begin();it!=l2.end();it++){
        cout<<(*it)<<" -->";
    }
    cout<<endl;
    //Iterate using For each Loop
    for(string s:l2){
        cout<<s<<"-->";
    }
    
    l2.push_back("Orange");
    l2.push_back("Carrot");
    l2.push_back("Lemon");
    l2.push_back("Carrot");
    cout<<endl;
    //Iterate using For each Loop
    for(string s:l2){
        cout<<s<<"-->";
    }
    cout<<endl;
    //Remove All the occurence of element in list
    string f;
    cin>>f;
    l2.remove(f);
    
    for(string s:l2){
        cout<<s<<"-->";
    }
    cout<<endl;
    
    //Erase particular index element at a list
    auto it=l2.begin();
    it++;
    l2.erase(it);
    
    for(string s:l2){
        cout<<s<<"-->";
    }
    cout<<endl;
    
    //We can insert element after the first element
    //the first paramter must be the address
    it=l2.begin();
    it++;
    l2.insert(it,"Fruit Juice");
    
    for(string s:l2){
        cout<<s<<"-->";
    }
    cout<<endl;
}