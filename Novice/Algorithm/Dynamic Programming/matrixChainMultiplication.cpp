#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the No Of Matrices:- ";
    cin>>n;
    int dimension[n+1];
    for(int i=0;i<=n;i++)
    {
        cin>>dimension[i];
    }
    int cost[n+1][n+1]={0};
    int s[n+1][n+1]={0};
    int col,q;
    for (int diagonal=1; diagonal<n; diagonal++)
    {
        for (int row=1; row<=n-diagonal; row++)
        {
            col = row+diagonal;
            cost[row][col]=INT_MAX;
            for (int k=row; k<col; k++)
            {
                q = cost[row][k] + cost[k+1][col] + dimension[row-1]*dimension[k]*dimension[col];
                if(q<cost[row][col])
                {
                    cost[row][col]=q;
                    s[row][col]=k;
                }    
            }
        }
    }
    cout<<"Cost of matrix multiplication is"<<cost[1][n]<<" "<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}