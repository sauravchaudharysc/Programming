//Implementaion of Insertion Operation On Max Heap
//After Insertion the tree should be a complete binary tree and Max Heap

/*If the array is reprsenting the heap. SO the element to be inserted should be inserted 
at the last of the array. So we will heapify and make the binary tree heapified.*/
#include<iostream>
#include<vector> //I used vector instead of array to make it size evergreen
using namespace std;

void heapify(vector<int>&heap,int idx){
    if(idx==0){
        return ;
    }
    int parentIdx=(idx-1)/2;
    if(heap[parentIdx]<heap[idx]){
        swap(heap[parentIdx],heap[idx]);
        heapify(heap,parentIdx);
    }else{
        return ;
    }
}

void insert(vector<int> &heap,int key){
    heap.push_back(key);
    heapify(heap,heap.size()-1);
}
void display(vector<int> &heap){
  for (int i=0;i<heap.size();i++){
      cout<<heap[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    vector<int>heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(heap,x);
    }
    display(heap);
    return 0;
}