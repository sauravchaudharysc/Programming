//Maximum Element in Every Window of Size K
// If the current element is greater than all the previous element are useless
/* Whatever element is at the very back of the Queue that element is going to be compared
with new element.And if the new element is greater than that element.Then there is no
point of using the back element*/
#include<iostream>
#include<deque>
using namespace std;

void printMax(int *arr,int n ,int k){
    deque<int>q;
    int i;
    for(i=0;i<k;i++){
        while(!q.empty() and arr[i] >=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";
        //Removing the element which are no longer in context of sliding window
        while(!q.empty() and q.front() <=  i-k){
            q.pop_front();
        }
        while(!q.empty() and arr[i] >=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];
}

int main()
{
    /*7
    12 1 78 90 57 89 56
    3 */
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    printMax(arr,n,k);
    return 0;
}