//Use of Inbuilt Binary Search and its prebuilt method

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,10,131,411,5131,53111};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    bool present=binary_search(arr,arr+n,key);
        if(present){
            cout<<"Found "<<endl;
        }else{
            cout<<"Not Found"<<endl;
        }
    //Two More Things
    int arr1[]={1,10,131,131,131,131,411,5131,53111};
    int n1=sizeof(arr)/sizeof(arr[0]);
    
    
    //To get the index of the element
    //It is an iterator and get the address of the element where it is stored. We can use int*
    
    //Lower Bound give the first element which is greater than equal to key
    auto it1=lower_bound(arr1,arr1+n1,131);
    cout<<it1-arr1<<endl; //to get the index we subtract it from address
    
    //Upper Bound gives the first element which is strictly greater than key
    auto it2=upper_bound(arr1,arr1+n1,131);
    cout<<it2-arr1<<endl;
    
    //So to get the frequence we can subtract it2-it1
    cout<<it2-it1<<endl;
}