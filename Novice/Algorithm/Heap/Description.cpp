//Priority Queues
/*Suppose that we have collection of elements . We have to extract element on the basis 
of certain Priority .So in those kind of scenario we implement priority queue type of
data structure*/

// Function Provided :- 
// 1.Insert
// 2.Delete 
// 3.Get -> this get function will make sure it will give the max or min priority element


//IMPLEMENTATION

1. Unsorted Arrays
 Insert :- We can directly insert an element at the end of array.
 Delete :- It will take O(N). Need to search O(N)
 get :- O(N).Need to search for min or max element.
 
2. Sorted Array 
 Insert :- Search for best possible place to insert. We can user insertion sort. O(N)
 Deletion :- It will also take O(N).We can implement binary Search
 get :- In order to get min and max we can get in O(1)
 
3. Unsorted List 
Insert :- O(1) . Insert at head will add at head and for tail insert at tail
Delete :- O(N). Search the element and get.
get :- O(N). Max or MIN element Search
 
4. Sorted List
Insert :- To maintain overall sort so its O(1)
Delete :- To delte min or max can be done in O(1) and for specific O(N)
get :- MIN or MAX will be done in O(1)

5. Binary Search Tree 
Insertion & Deletion are Both LOGN time. When BST Is balanced. In general it is O(H).

6. Binary Heap 
It is a binary tree. It is a complete binary tree.Every child has priority lesser than
parent.
        Insertion :- O(LogN)
        Deletion :- O(LogN)
        get :- O(1)

