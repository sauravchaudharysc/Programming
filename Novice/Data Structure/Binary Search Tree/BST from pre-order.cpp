//Construct a Tree From Preorder Traversal
// It can done easily using insert function.

//But for sorted input  it will form a skewed tree.If we use insert function
//So each insertion it will be O(H). SO overall insertion will comeout to be 0(N^2).

//So we can do this easily by other approach.
//We can take it inorder. Since inorder is always sorted 
//And we have Preorder. So using Preorder and inorder we can make it in O(N)