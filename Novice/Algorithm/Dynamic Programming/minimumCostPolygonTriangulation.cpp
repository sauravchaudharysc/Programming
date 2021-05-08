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

double minimumCostPolygonTriangulation(Point points[],int i,int j)
{
    /*Assume i=0 then j must be either 2 or greater than it.So i satisifies
    the condition of adjacent vertices.*/
    if(j<i+2){
        return 0;
    }
    
    double res = INT_MAX;
    /*Here the k iterate to all the points and divide the polygon into 
    sub-polygon.The left side of polygon is from i to k and 
    right side polygon is from k to j.*/
    for(int k=i+1;k<j;k++){
        res=min(res,(minimumCostPolygonTriangulation(points,i,k)+
                minimumCostPolygonTriangulation(points,k,j)+
                cost(points,i,k,j)));
    /*The cost function calculate the cost of it.Cost of each sub-problem
    is calculated and which leads to the result of larger problem.*/            
    }
    return res;
}

int main()
{
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}}; 
    int n=sizeof(points)/sizeof(points[0]);
    cout<<minimumCostPolygonTriangulation(points,0,n-1);
}