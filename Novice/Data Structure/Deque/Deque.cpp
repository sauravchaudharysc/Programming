//Deque
/*Deque stands for Doubly ended queue.It is pronounced as "deck".
It is sequence container with dyanmic sizes that can be expanded 
or contracted on both ends(either front or back).It has a feature 
of random access. It doesnt get contiguous memory.Random chunk of
memory are allocated and linked.*/

//Tell the maximum element of a sub-array of size k.
/*
Brute Force
Track The Maximum element from i to i+k.*/

/*Deque
Sliding window Technique*/

#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int n;
    int a[10000];
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    //We have to process first K element seperately
    deque<int>Q(k);
    int i;
    for(i=0;i<k;i++){
        /*Check the element pushed in queue.Index of 
        element is stored in queue if the element present at index 
        store in queue is smaller then current element index 
        pop the element and so on. Push the current element index*/
        while(!Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i); 
    }
    //Process the remaining element
    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";

    //1.Remove the element which arent part of window(Contraction)
    while((!Q.empty()) && (Q.front()<=i-k)){
        Q.pop_front();
    }
    //2.Remove the element which are not useful and are in window
    while((!Q.empty()) && a[i]>=a[Q.back()]){
        Q.pop_back();
    }
    //3.Add the New element(Expansion)
    Q.push_back(i);
    } 
    cout<<a[Q.front()]<<endl;
} 