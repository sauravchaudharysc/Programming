/*Given an array arr of n length. You will be given Q queries for the array. Each query contains a number N.You have to determine whether a number exist in the array or not

Input Format
First line of input contains number of test cases T. First line of each case contains an integer L denoting the length of the array. The next line contains L space separated integers. The next line contains an integer Q denoting the number of queries. The next Q lines contains a number N to be searched in the array.

Constraints
1<=t<=12
1<=L<=10^5 (n=number of elements in array).
-10^5<=A[i]<=10^5 (A[i]=ith element of array).

1<=Q<=10^4
-10^5<=x<=10^5

Output Format
For each Query print “Yes” if the number is present and “No” if it’s not.

Sample Input
1
6
12 3 -67 67 34 2
4
4
5
67
7
Sample Output
No
No
Yes
No*/

/*Everytime is take an input L the integers, i treat the input as a key in the hashmap 
and associate 1 as a value to it.And for each element to searched . I simiply check for that
index in the hashmap if its present i print Yes else No*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            hash[x]=1;
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int test;
            cin>>test;
            if(hash[test]==1){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
}