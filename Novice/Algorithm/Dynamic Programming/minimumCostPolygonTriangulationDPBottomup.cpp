/*The triangulation polygon is formed by drawing diagonals between non-adjacent
vertices such that the diagonals nevers intersect.The problem in to find the cost
triangulation with minimum cost.*/
/*Cost of triangulation is sum of the weights of it components triangles.
Weight of each triangles is its perimeter.*/
/*The problem has a recursive sub-structure.The idea is to divide the poylgon
into sub-structure
                    (i)A single triangle
                   (ii)Sub-Polygon to the left
                  (iii)Sub-Polygon to the right*/
#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

double min(double x,double y)
{
    return (x<=y)?x:y;
}

double distance(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
/*dist ==> i--k+k--j+j--i*/

double cost(Point points[],int i,int k,int j)
{
    Point p1=points[i],p2=points[k],p3=points[j];
    return distance(p1,p2)+distance(p2,p3)+distance(p3,p1);
}

double minimumCostPolygonTriangulation(Point points[],int n)
{
    if(n<3){
       return 0;
    }
    
    /*DP Table to store cost of i to j.We fill the table in bottom up 
      manner and as in recursion we go for a same problem again and 
      again in this we avoid it by storing the value in dp table.
    */
    double dp[n][n]={0};
    /**/
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0,j=gap; j<n;i++,j++)
        {
            if(j<i+2){
               dp[i][j]=0.0;
            }   
            else{
                dp[i][j] =INT_MAX;
                for(int k=i+1;k<j;k++){
                    double val=dp[i][k]+dp[k][j]+cost(points,i,k,j);
                    dp[i][j]=min(val,dp[i][j]);
                }
            } 
        }
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
         cout<<dp[i][j]<<"\t\t";
        }
        cout<<endl;
    }
return dp[0][n-1];
}

int main()
{
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}}; 
    int n=sizeof(points)/sizeof(points[0]);
    cout<<minimumCostPolygonTriangulation(points,n);
}