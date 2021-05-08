#include<bits/stdc++.h>
using namespace std;
int countBoardPath(int start,int end)
{
    if(start==end)
    {
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    int count=0;
    for(int dice=1;dice<=6;dice++)
    {
        count+=countBoardPath(start+dice,end);
    }
    return count;
}

int main()
{
    cout<<countBoardPath(0,2);
}