// Set STL
// Set is container used to store unique collection of element.Set is bydefault ordered.
// You cant update the value of set once inserted. 
// For updation you have to delete that element and push another element.


/*
Set is storing unique element*/
#include<iostream>
#include<set>
using namespace std;
int main()
{
    int arr[]={10,20,11,9,8,11,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    //To remove Element From Set Container
    s.erase(10);
    auto it=s.find(11);
    s.erase(it);
    
    //traversal
    for(set<int> :: iterator it=s.begin(); it!=s.end();it++){
        cout<<*(it)<<" ";
    }
}