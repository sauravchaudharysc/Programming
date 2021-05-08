/*If we want to store the value in pairs in SET . We can use pair with set to do so.*/
/*Data is going to be sorted. If the first value is same then it will be sorted 
on the basis of second value.*/


/*
lower_bound >=
upperbound >
*/
#include<iostream>
#include<set>
#include<climits>
using namespace std;
int main()
{
   set<pair<int,int>>s;
   s.insert(make_pair(10,1));
   s.insert(make_pair(20,1));
   s.insert(make_pair(20,100));
   s.insert(make_pair(5,1));
   s.insert(make_pair(5,3));
   s.erase(make_pair(5,3));
   s.erase(s.find(make_pair(5,1)));
   auto it1=s.lower_bound(make_pair(20,1));
   //Arrow must be used
    cout<<it1->first<<" "<<it1->second<<endl;
   
   auto it2=s.upper_bound(make_pair(20,1));
   //Arrow must be used
    cout<<it2->first<<" "<<it2->second<<endl;
   
   //We want a pair greater than ceratin value
    it2=s.upper_bound(make_pair(10,INT_MAX));
    cout<<it2->first<<" "<<it2->second<<endl;
   
   
   for(auto it:s){
       cout<<it.first<<" "<<it.second<<endl;
   }
}