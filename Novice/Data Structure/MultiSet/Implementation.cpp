//MultiSet
/*It is a variation of set. It can store multiple element having same value.
All element are store in specific order.Once the values are inserted in set cant
be modified. 

It is associative container-> Element are referred by their value and not by the index
Underlying data structure = BST
*/

#include<iostream>
#include<set>
using namespace std;
int main()
{
    int arr[]={10,20,30,30,30,30,30,20,10,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    multiset<int> m(arr,arr+n);
    
    //Erase
    m.erase(20); //It removes all occurences
    
    //Insert 
    m.insert(80); //Insert 80 in the set 
    
    //Count to count occurences 
    cout<< "Count of "<<m.count(10)<<endl;
    
    //To get an interator to particular Element
    auto it=m.find(30); //gives first element equals to 30
    cout<<(*it)<<endl;
    
    //To get all element which are equal to 30
    // so for this i need to create pair of iterator m.equal_range(30);
    //we can use typedef
    pair<multiset<int>::iterator,multiset<int>::iterator>range= m.equal_range(30);
    for(auto it=range.first;it!=range.second;it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //Lower >= and Upper Bound >
    for(auto it=m.lower_bound(10); it!=m.upper_bound(77);it++){
        cout<<*it<<" ->";
    }
    cout<<endl;
    for(int x:m)
    {
        cout<<x<<" ";
    }
}