/*Given K sorted arrays each with N elements merge them and output the sorted array

Input Format
First line contains 2 space separated integers K and N.
K is number of arrays.
N is number of elements in each array.
Next K lines contain N space separated integers each where ith line denotes the element of ith sorted array.

Constraints
Elements of array <= |10^15|
N <= 10^5
K <= 10

Output Format
Single line consisting of space separated numbers

Sample Input
3 4
1 3 5 7
2 4 6 8
0 9 10 11
Sample Output
0 1 2 3 4 5 6 7 8 9 10 11
Explanation
If we were to combine all the arrays into one and then sort it , the output would be as above.*/

#include<bits/stdc++.h>
using namespace std;


/*A pair of pairs,first elements is going to store value
second element index of array and third element store the 
index of element in the array.*/
typedef pair<int,pair<int,int>>ppi;

vector<int> mergeKArrays(vector<vector<int>>arr){
    vector<int> output;
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    
    //Push the first element,it array index and index of element in array is zero
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0], { i, 0 }});
    }
    //Now one by one get the minimum element from min heap and replace it with 
    //next element from array.
    while(pq.empty()==false){
        ppi curr=pq.top(); //The minimum element from min heap
        pq.pop(); //Pop the element 
        //i ==> Array Number
            int i=curr.second.first;
        //j ==> Index in the Array Number
            int j=curr.second.second;
        
        //Answer in the output array    
        output.push_back(curr.first);   
        
        //The next element belongs to same array as current 
        if(j+1<arr[i].size()){
            pq.push({arr[i][j+1],{i,j+1}});
        }
    }
    return output;
}

int main(){
    int row;
    cin>>row;
    vector<vector<int>>vec(row);
    int n;
    cin>>n;
    for(int i=0;i<row;i++){
        vec[i]=vector<int>(n);
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            vec[i][j]=x;
        }
    }
    vector<int>output=mergeKArrays(vec);
    
     for (auto x : output) 
        cout << x << " "; 
    cout<<endl;
}