#include<bits/stdc++.h>
using namespace std;
void findDuplicate(int A[]){
  int slow = A[0];
  int fast = A[A[0]];
  //Move Slow One Step and Fast Two Step, to detect cycle.
  while (slow != fast) {
    slow = A[slow];
    fast = A[A[fast]];
  }
  
  //Move slow to the starting point .
  slow = 0;
  //Fast remains withing the cycle it moves within the cycle.
  //Both moves at same speed. They will intersect at cycle.
  while (slow != fast) {
    slow = A[slow];
    fast = A[fast];
  }
    
  cout<<slow<<endl;
}

int main(){
    int A[] = { 2, 6, 4, 1, 3, 1, 5 }; 
  
    findDuplicate(A);
}