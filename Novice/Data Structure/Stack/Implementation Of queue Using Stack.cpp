//Implement Queue using Stack
/*
Enqueue :- It can be achieved in O(1) using stack push oepration
Dequeue :- Least Recently Added Element.We can use helper stack. 
And we will do pop operation till my primary stack size becomes one.
So when primary stack size becomes one.The last element is the element 
to be poped. And after pop we will push back the element from helper array
to the primary array.

*/