#include<bits/stdc++.h>
using namespace std;
int tilingProblem(int n)
{
    if(n== 1 or n==2)
    {
        return n;
    }
    return tilingProblem(n-1)+tilingProblem(n-2);
}
int main()
{
    cout<<tilingProblem(4);
}