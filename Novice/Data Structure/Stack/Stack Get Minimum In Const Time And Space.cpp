//A Stack that supports getMin() in O(1) time and O(1) extra space

/*Insertion.
We will maintain a current_minimum.
Let x be the insertion element
If x is greater than current_minimum or equal to current_minimum .Simply insert x
If x is less than current_minimum then push 2*x - current_minimum and 
update current_minimum with x.*/

/*
Pop
IF y is greater than or equal to current_minimum then simply pop it.
If less than the current_minimum . newcurrent_minimum=2*current_minimum - y 
pop the y.*/

/*
Push
1st elemetnt is 3.Push it. So current_minimum is 3 
2nd elemetnt is 5.Push it. So current_minimum is 3. 
3rd element is 2.So push into stack 2*2-3=1 and current_minimum is 2
4th element is 1.So push 2*1-2=0. Push 0 in stack and current_minimum is 1.*/

/*
Same while poping if element is greater or equal do nothing.
If less than
newcurrent_minimum=2*current_minimum - y.*/

/*This works because if
For Push is smaller element encountered
2*x- current_minimum < x
x- current_minimum < 0;
add x on both side
2*x- current_minimum < x
*/

/*
In case of Pop
 If the value is greater than current_minimum then
    The element poped is equal to 
      y = 2*x- current_minimum
    
    Subsituting the value of y in pop eqn
    newcurrent_minimum= 2*current_minimum - y.
  
    newcurrent_minimum=2*current_minimum-(2*x- current_minimum)
    newcurrent_minimum=current_minimum;
*/
