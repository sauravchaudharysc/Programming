#include<bits/stdc++.h>
using namespace std;
int main()
{
 int arr[]={1,9,11,19,100};
 int n=sizeof(arr)/sizeof(int);
 int key;
 cin>>key;
 bool present=binary_search(arr,arr+n,key);
 if(present)
 {
     cout<<"element present";
 }
 else
 {
     cout<<"element not present"<<endl;
 }
 
 //Get the index of element
 //lower_bound(s,e,key) and upper_bound(s,e,key); 
 //Frequency=Upper-lower
 
 //Lower Bound
 auto lb=lower_bound(arr,arr+n,11); // gives greater than equals to key
 cout<<endl<<"Lower bound is "<<(lb-arr); //lb-arr==n element not present
 
 //Upper Bound
 auto ub=upper_bound(arr,arr+n,11); //ub-arr==n element not present
 cout<<endl<<"Lower bound is "<<(ub-arr)<<endl; //strictly greater than key
 
 //Frequency
 cout<<ub-lb;
}

