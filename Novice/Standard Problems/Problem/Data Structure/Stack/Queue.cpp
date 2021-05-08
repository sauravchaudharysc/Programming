/*To implement queue simply use 2 stack and to push simply use the stack push. To 
dequeue we need to pop all the element except the last one . And the last element is 
the dequeued value and again push the second stack element into first stack\*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>S1,S2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        S1.push(i);
    }
    for(int i=0;i<n;i++){
        S2.push(S1.top());
        S1.pop();
    }
    for(int i=0;i<n;i++){
        cout<<S2.top()<<" ";
        S2.pop();
    }
}