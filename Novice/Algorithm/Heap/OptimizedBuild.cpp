//fill the array from last. 

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
void downHeapify(vector<int>&heap , int idx){
    int lchild=2*idx+1;
    int rchild=2*idx+2;
    //Occurs in case of leaf nodes
    if(lchild >= heap.size() and rchild>=heap.size()){
        return;
    }
    int largestIdx=idx;
    if(lchild < heap.size() and heap[lchild] >heap[largestIdx]){
        largestIdx=lchild;
    }
    if(rchild < heap.size() and heap[rchild] >heap[largestIdx]){
        largestIdx=rchild;
    }
    if(largestIdx == idx){
        return;
    }
    swap(heap[idx],heap[largestIdx]);
    downHeapify(heap,largestIdx);
}

void deletePeek(vector<int> &heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}

//Normally it take nlogn . This optmized approach take O(N)
void buildHeapOptimized(vector<int> &heap){
    for(int i=head.size()-1;i>=0;i--){
        downHeapify(heap,i);
    }
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
    deletePeek(heap);
    
    display(heap);
    return 0;
}