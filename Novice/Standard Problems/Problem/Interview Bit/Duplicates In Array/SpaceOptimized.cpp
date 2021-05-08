/*A space optimized solution is to break the given range (from 1 to n) into blocks of size equal to sqrt(n). We maintain the count of elements belonging to each block for every block. Now as the size of array is (n+1) and blocks are of size sqrt(n), then there will be one such block whose size will be more than sqrt(n). For the block whose count is greater than sqrt(n), we can use hashing for the elements of this block to find which element appears more than once.

Explanation:
The method described above works because of the following two reasons:

There would always be a block which has count greater than sqrt(n) because of one extra element. Even when one extra element has been added it will occupy a position in one of the blocks only, making that block to be selected.
The selected block definitely has a repeating element. Consider that ith block is selected. Size of the block is greater than sqrt(n) (Hence, it is selected) Maximum distinct elements in this block = sqrt(n). Thus, size can be greater than sqrt(n) only if there is a repeating element in range ( i*sqrt(n), (i+1)*sqrt(n) ].
Note: The last block formed may or may not have range equal to sqrt(n). Thus, checking if this block has a repeating element will be different than other blocks. However, this difficulty can be overcome from implementation point of view by initialising the selected block with the last block. This is safe because at least one block has to get selected.

Below is the step by step algorithm to solve this problem:

Divide the array in blocks of size sqrt(n).
Make a count array which stores the count of element for each block.
Pick up the block which has count more than sqrt(n), setting the last block
as default.
For the elements belonging to the selected block, use the method of hashing(explained in next step) to find the repeating element in that block.
We can create a hash array of key value pair, where key is the element in the block and value is the count of number of times the given key is appearing. This can be easily implemented using unordered_map in C++ STL.
Below is the implementation of above idea:*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find one of the repeating 
// elements 
int findRepeatingNumber(const int arr[], int n) 
{ 
    // Size of blocks except the 
    // last block is sq 
    int sq = sqrt(n); 
  
    // Number of blocks to incorporate 1 to 
    // n values blocks are numbered from 0 
    // to range-1 (both included) 
    int range = (n / sq) + 1; 
  
    // Count array maintains the count for 
    // all blocks 
    int count[range] = {0}; 
  
    // Traversing the read only array and 
    // updating count 
    for (int i = 0; i <= n; i++) 
    { 
        // arr[i] belongs to block number 
        // (arr[i]-1)/sq i is considered 
        // to start from 0 
        count[(arr[i] - 1) / sq]++; 
    } 
  
    // The selected_block is set to last 
    // block by default. Rest of the blocks 
    // are checked 
    int selected_block = range - 1; 
    for (int i = 0; i < range - 1; i++) 
    { 
        if (count[i] > sq) 
        { 
            selected_block = i; 
            break; 
        } 
    } 
  
    // after finding block with size > sq 
    // method of hashing is used to find 
    // the element repeating in this block 
    unordered_map<int, int> m; 
    for (int i = 0; i <= n; i++) 
    { 
        // checks if the element belongs to the 
        // selected_block 
        if ( ((selected_block * sq) < arr[i]) && 
                (arr[i] <= ((selected_block + 1) * sq))) 
        { 
            m[arr[i]]++; 
  
            // repeating element found 
            if (m[arr[i]] > 1) 
                return arr[i]; 
        } 
    } 
  
    // return -1 if no repeating element exists 
    return -1; 
} 
  
// Driver Program 
int main() 
{ 
    // read only array, not to be modified 
    const int arr[] = { 1, 1, 2, 3, 5, 4 }; 
  
    // array of size 6(n + 1) having 
    // elements between 1 and 5 
    int n = 5; 
  
    cout << "One of the numbers repeated in"
         " the array is: "
         << findRepeatingNumber(arr, n) << endl; 
} 