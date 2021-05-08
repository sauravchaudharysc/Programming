/*Given an infinite grid, initial cell position (x, y) and a sequence of other cell position which needs to be covered in the given order. The task is to find the minimum number of steps needed to travel to all those cells.
Note: Movement can be done in any of the eight possible directions from a given cell i.e from cell (x, y) you can move to any of the following eight positions:(x-1, y+1), (x-1, y), (x-1, y-1), (x, y-1), (x+1, y-1), (x+1, y), (x+1, y+1), (x, y+1) is possible.

Examples:

Input: points[] = [(0, 0), (1, 1), (1, 2)]
Output: 2
Move from (0, 0) to (1, 1) in 1 step(diagonal) and
then from (1, 1) to (1, 2) in 1 step (rightwards)

Input: points[] = [{4, 6}, {1, 2}, {4, 5}, {10, 12}]
Output: 14
Move from (4, 6) -> (3, 5) -> (2, 4) -> (1, 3) ->
(1, 2) -> (2, 3) -> (3, 4) ->
(4, 5) -> (5, 6) -> (6, 7) ->
(7, 8) -> (8, 9) -> (9, 10) -> (10, 11) -> (10, 12)

Approach 
Since all the given points are to be covered in the specified order. Find the minimum number of steps required to reach from a starting point to next point, then the sum of all such minimum steps for covering all the points would be the answer. One way to reach from a point (x1, y1) to (x2, y2) is to move abs(x2-x1) steps in the horizontal direction and abs(y2-y1) steps in the vertical direction, but this is not the shortest path to reach (x2, y2). The best way would be to cover the maximum possible distance in a diagonal direction and remaining in horizontal or vertical direction.
If we look closely this just reduces to the maximum of abs(x2-x1) and abs(y2-y1). Traverse for all points and summation of all diagonal distance will be the answer.*/


#include<bits/stdc++.h>
using namespace std;
class point{
    public:
        int x;
        int y;
};
int count(point p1,point p2){
    int dx=abs(p1.x-p2.x);
    int dy=abs(p1.y-p2.y);
    return max(dy,dx);
}
int minSteps(point arr[],int n){
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=count(arr[i],arr[i+1]);
    }
    return sum;
}
int main(){
    point arr[] = { { 4, 6 }, { 1, 2 }, { 4, 5 }, { 10, 12 } }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << minSteps(arr, n);
}