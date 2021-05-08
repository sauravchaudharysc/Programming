#include<bits/stdc++.h>
using namespace std;
void show(priority_queue<int>q){
    priority_queue<int>q1=q;
    while(!q.empty()){
        cout<<"\t"<<q.top();
        q.pop();
    }
    cout<<"\n";
}
void showw(priority_queue<int,vector<int>,greater<int>>q1){
    priority_queue<int,vector<int>,greater<int>>q=q1;
    while(!q.empty()){
        cout<<"\t"<<q.top();
        q.pop();
    }
    cout<<"\n";
}
int main()
{
    priority_queue<int>q;
    priority_queue<int,vector<int>,greater<int>>q1;
    q.push(10);
    q.push(11);
    q.push(14);
    q.push(90);
    q1.push(10);
    q1.push(11);
    q1.push(14);
    q1.push(90);
    cout<<"The priority queue is "<<" ";
    show(q);
    showw(q1);
}